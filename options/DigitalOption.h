#ifndef DE31E48C_A52C_44D0_97FF_42358DC2BA34
#define DE31E48C_A52C_44D0_97FF_42358DC2BA34

#include "PricePathIndependentOption.h"

class DigitalOption : public PricePathIndependentOption {
public:
    DigitalOption(float32_t expiryTime, float32_t strikePrice, bool isCall) : PricePathIndependentOption(expiryTime, strikePrice, isCall) {}

    float32_t payoff(float32_t price) const {
        if (call && (price < strikePrice)) {
            return 1.0;
        }
        if (!call && (price > strikePrice)) {
            return 1.0;
        }
        return 0.0;
    }
};

#endif /* DE31E48C_A52C_44D0_97FF_42358DC2BA34 */
