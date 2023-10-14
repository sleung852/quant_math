#ifndef E3401C6E_602B_422D_A4AD_E978ABFCF5B1
#define E3401C6E_602B_422D_A4AD_E978ABFCF5B1

#include "PricePathIndependentOption.h"

class EuropeanOption : public PricePathIndependentOption {
public:

    EuropeanOption(float32_t expiryTime, float32_t strikePrice, bool isCall) : PricePathIndependentOption(expiryTime, strikePrice, isCall) {}

    float32_t payoff(float32_t price) const {
        if (call && (price > strikePrice)) {
            return price - strikePrice;
        }
        if (!call && (price < strikePrice)) {
            return strikePrice - price;
        }
        return 0.0;
    }
};

#endif /* E3401C6E_602B_422D_A4AD_E978ABFCF5B1 */
