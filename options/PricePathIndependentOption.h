#ifndef D5533399_AEFF_496B_924F_F0902618A233
#define D5533399_AEFF_496B_924F_F0902618A233

#include "PricePathIndependentPricable.h"
#include "Option.h"

class PricePathIndependentOption : public PricePathIndependentPricable, public Option {
public:
    PricePathIndependentOption(float32_t expiryTime, float32_t strikePrice, bool isCall) : PricePathIndependentPricable(expiryTime), Option(strikePrice, isCall) {}
    virtual ~PricePathIndependentOption() {}

    virtual float32_t payoff(float32_t price) const = 0;
};

#endif /* D5533399_AEFF_496B_924F_F0902618A233 */
