//
// Created by See Leung on 13/10/2023.
//

#ifndef QUANT_MATH_GEOMETRICASIANOPTION_H
#define QUANT_MATH_GEOMETRICASIANOPTION_H

#include "PricePathDependentOption.h"
#include <cmath>

class GeometricAsianOption : public PricePathDependentOption {
public:
    float32_t payoff(std::vector<float32_t> prices) const {
        float32_t log_mean = 0.0;
        for (auto const &price: prices) {
            log_mean += log(price) / prices.size();
        }
        float32_t average = exp(log_mean);
        if (call) {
            float32_t out = average - strikePrice;
            return out > 0.0 ? out : 0.0;
        }
        float32_t out = strikePrice - average;
        return out > 0.0 ? out : 0.0;
    }
};

#endif //QUANT_MATH_GEOMETRICASIANOPTION_H
