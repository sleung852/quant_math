#ifndef A93E4E59_9761_4389_9914_BCF3099F64EA
#define A93E4E59_9761_4389_9914_BCF3099F64EA

#include "../options/PricePathIndependentPricable.h"
#include "../model/ComputationMode.h"
#include "GeometricBrownianMotionPricer.h"
#include "arm_neon.h"

class MonteCarloPricer {
private:
    float32_t riskFreeRate;
    long nScenarios;
    long nSteps;

    float32_t price_norm(PricePathIndependentPricable& pricable, GeometricBrownianMotionPricer& pricer, bool direction=true) const {
        float32_t mean = 0.0;
        float32_t toDate = pricable.getExpiryTime();
        for (size_t i = 0; i < nScenarios; i++) {
            std::vector<float32_t> paths = pricer.generateRiskNeutralPricePath(toDate, nSteps, direction);
            float32_t price = paths.back();
            float32_t payoff = pricable.payoff(price);
            mean += payoff/nScenarios;
        }
        return exp(-riskFreeRate*toDate)*mean;
    }

    float32_t price_simd(PricePathIndependentPricable& pricable, GeometricBrownianMotionPricer& pricer, bool direction=true) const {
        float32x4_t meanVector = vdupq_n_f32(0.0f);
        float32x4_t countVector = vdupq_n_f32(nScenarios);
        const int size = 4;
        int numIterations = nScenarios / size;
        float32_t toDate = pricable.getExpiryTime();

        float32_t payoffs[4];
        float32_t price;
        for (size_t i = 0; i < numIterations; i++) {
            for (size_t j = 0; j < size; j++) {
                std::vector<float32_t> paths = pricer.generateRiskNeutralPricePath(toDate, nSteps, direction);
                price = pricable.payoff(paths.back());
                payoffs[j] = pricable.payoff(price);
            }
            float32x4_t payoffs_vector = vld1q_f32(payoffs);
            float32x4_t mean_payoffs_vector = vdivq_f32(payoffs_vector, countVector);
            meanVector = vaddq_f32(meanVector, mean_payoffs_vector);
        }

        float32x2_t sum2 = vadd_f32(vget_low_f32(meanVector), vget_high_f32(meanVector));
        float32x2_t sum = vpadd_f32(sum2, sum2);
        float32_t mean = vget_lane_f32(sum, 0);

        for (int i = 0; i < numIterations % 4; i++) {
            std::vector<float32_t> paths = pricer.generateRiskNeutralPricePath(toDate, nSteps, direction);
            price = pricable.payoff(paths.back());
            mean += pricable.payoff(price) / nScenarios;
        }
        return exp(-riskFreeRate*toDate)*mean;
    }

    float32_t price_gpu(PricePathIndependentPricable& pricable, GeometricBrownianMotionPricer& pricer, bool direction=true) const {
        float32_t mean = 0.0;
        float32_t toDate = pricable.getExpiryTime();
        for (size_t i = 0; i < nScenarios; i++) {
            std::vector<float32_t> paths = pricer.generateRiskNeutralPricePath(toDate, nSteps, direction);
            float32_t price = paths.back();
            float32_t payoff = pricable.payoff(price);
            mean += payoff/nScenarios;
        }
        return exp(-riskFreeRate*toDate)*mean;
    }


public:
    MonteCarloPricer(float32_t riskFreeRate = 0.0, long nScenarios = 1000000, long nSteps = 1000) : riskFreeRate(riskFreeRate), nScenarios(nScenarios), nSteps(nSteps) {}

    float32_t price(PricePathIndependentPricable& pricable, GeometricBrownianMotionPricer& pricer, ComputationMode mode = ComputationMode::native, bool direction=true) const {
        switch (mode) {
            case native: 
                return price_norm(pricable, pricer, direction);
            case simd:
                return price_simd(pricable, pricer, direction);
        }
        return price_norm(pricable, pricer);
    }
};


#endif /* A93E4E59_9761_4389_9914_BCF3099F64EA */
