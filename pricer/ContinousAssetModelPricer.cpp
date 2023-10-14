
#include "ContinousAssetModelPricer.h"

ContinuousAssetModelPricer::ContinuousAssetModelPricer(float32_t drift, float32_t volatility) : GeometricBrownianMotionPricer(drift, volatility) {}

std::vector<float32_t> ContinuousAssetModelPricer::generateRiskNeutralPricePath(float32_t toDate, int nSteps, bool dir) {
    std::vector<float32_t> pricePath(nSteps, 0.0);
    std::vector<float32_t> epsilons = Stat::randn(nSteps);
    float32_t dt = toDate / nSteps;
    float32_t mid_part = (drift - 0.5 * volatility * volatility) * dt;
    float32_t direction;
    if (dir) direction = 1.0;
    else direction = -1.0;
    for (size_t i = 1; i < nSteps; i++) {
        float32_t exponent = mid_part + volatility * sqrt(dt) * epsilons[i] * direction;
        pricePath[i] = pricePath[i-1] * exp(exponent);
    }
    return pricePath;
}