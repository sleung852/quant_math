//
// Created by See Leung on 3/10/2023.
//

#ifndef QUANT_MATH_ASSETPRICER_H
#define QUANT_MATH_ASSETPRICER_H

#include <vector>
#include <cmath>
#include "../math_util/stat.h"



// Geometric Brownian motion is a mathematical model used to describe the stochastic movement of a variable over time, often applied to financial asset prices.
// Geometric Brownian motion assumes that the logarithm of the variable follows a Brownian motion with drift and volatility.
class GeometricBrownianMotionPricer {
public:
    GeometricBrownianMotionPricer(float32_t drift, float32_t volatility) : drift(drift), volatility(volatility) {};
    virtual ~GeometricBrownianMotionPricer() {}
    virtual std::vector<float32_t> generateRiskNeutralPricePath(float32_t toDate, int nSteps, bool dir = true) = 0;
    
protected:
    float32_t drift;
    float32_t volatility;
};


#endif //QUANT_MATH_ASSETPRICER_H
