#ifndef DF49D3A5_A276_4D6C_95E5_56783092383C
#define DF49D3A5_A276_4D6C_95E5_56783092383C

#include "MonteCarloPricer.h"

class MonteCarloVarianceReductionPricer {
private:
    MonteCarloPricer monte_carlo_pricer;

public:
    MonteCarloVarianceReductionPricer(float32_t riskFreeRate = 0.0, long nScenarios = 1000, long nSteps = 1000) : monte_carlo_pricer(riskFreeRate, nScenarios/2.0, nSteps) {}

    float32_t price(PricePathIndependentPricable& pricable, GeometricBrownianMotionPricer& pricer, ComputationMode mode = ComputationMode::native) const {
        float32_t price_up;
        float32_t price_down;
        switch (mode) {
            case native: 
                price_up = monte_carlo_pricer.price(pricable, pricer, ComputationMode::native, true);
                price_down = monte_carlo_pricer.price(pricable, pricer, ComputationMode::native, false);
                return (price_up + price_down) / 2.0;
            case simd:
                price_up = monte_carlo_pricer.price(pricable, pricer, ComputationMode::simd, true);
                price_down = monte_carlo_pricer.price(pricable, pricer, ComputationMode::simd, false);
                return (price_up + price_down) / 2.0;
        }
    }
};


#endif /* DF49D3A5_A276_4D6C_95E5_56783092383C */
