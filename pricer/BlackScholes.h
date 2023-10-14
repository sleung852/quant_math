//
// Created by See Leung on 26/9/2023.
//

#ifndef QUANT_MATH_BLACKSCHOLES_H
#define QUANT_MATH_BLACKSCHOLES_H

#include "../common.h"
#include "math.h"
#include "../math_util/stat.h"
#include "../options/Pricable.h"
#include "../options/EuropeanOption.h"
#include "../model/ComputationMode.h"
#include "GeometricBrownianMotionPricer.h"
#include "arm_neon.h"

class BlackScholes {
private:
    float32_t price(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T, bool isCall);
public:
    float32_t price(EuropeanOption& option, float32_t S, float32_t r, float32_t sigma);
    float32_t delta(EuropeanOption& option, float32_t S, float32_t r, float32_t sigma, float32_t h = 1e-06);
    float32_t d1(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T);
    float32_t d2(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T);
};


#endif //QUANT_MATH_BLACKSCHOLES_H
