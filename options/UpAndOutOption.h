//
// Created by See Leung on 13/10/2023.
//

#ifndef QUANT_MATH_UPANDOUTOPTION_H
#define QUANT_MATH_UPANDOUTOPTION_H

#include "KnockOutOption.h"

class UpAndOutOption : public KnockOutOption {
    UpAndOutOption(float32_t expiryTime, float32_t strikePrice, bool isCall, float32_t barrier) : KnockOutOption(expiryTime, strikePrice, isCall, barrier) {}

    float32_t payoff(std::vector<float32_t> prices) const {
        for (auto const &price: prices) {
            if (price > getBarrier()) return 0;
        }
        float32_t price = prices.back();
        if (call && (price < strikePrice)) {
            return strikePrice - price;
        }
        if (!call && (price > strikePrice)) {
            return price - strikePrice;
        }
        return 0.0;
    }
};

#endif //QUANT_MATH_UPANDOUTOPTION_H
