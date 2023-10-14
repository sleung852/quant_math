//
// Created by See Leung on 11/10/2023.
//

#ifndef QUANT_MATH_ARITHEMATICASIANOPTION_H
#define QUANT_MATH_ARITHEMATICASIANOPTION_H

#include "PricePathDependentOption.h"
#include "../math_util/operations.h"

class ArithmeticAsianOption : public PricePathDependentOption {
public:
    float32_t payoff(std::vector<float32_t> prices) const {
        float32_t average = operations::mean(prices);
        if (call) {
            float32_t out = average - strikePrice;
            return out > 0.0 ? out : 0.0;
        }
        float32_t out = strikePrice - average;
        return out > 0.0 ? out : 0.0;
    }
};

#endif //QUANT_MATH_ARITHEMATICASIANOPTION_H
