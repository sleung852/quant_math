#ifndef B019E812_2470_4C9B_92DD_0CD09C1967B3
#define B019E812_2470_4C9B_92DD_0CD09C1967B3

#include "arm_neon.h"
#include "Pricable.h"

class PricePathIndependentPricable : public Pricable {
public:
    PricePathIndependentPricable(float32_t expiryTime) : Pricable(expiryTime) {}
    virtual ~PricePathIndependentPricable() {}
    virtual float32_t payoff(float32_t price) const = 0;
};

#endif /* B019E812_2470_4C9B_92DD_0CD09C1967B3 */
