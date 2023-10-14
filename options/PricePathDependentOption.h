#ifndef D03FFD0D_4D03_44FF_96DE_622440D1C669
#define D03FFD0D_4D03_44FF_96DE_622440D1C669

#include "PricePathDependentPricable.h"
#include "Option.h"

class PricePathDependentOption : public PricePathDependentPricable, public Option {
public:
    PricePathDependentOption(float32_t expiryTime, float32_t strikePrice, bool isCall) : PricePathDependentPricable(expiryTime), Option(strikePrice, isCall) {}
    virtual ~PricePathDependentOption() {}
    virtual float32_t payoff(std::vector<float32_t> prices) const = 0;

};

#endif /* D03FFD0D_4D03_44FF_96DE_622440D1C669 */
