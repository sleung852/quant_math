#ifndef E4B41828_3660_446D_A982_578706EA07E5
#define E4B41828_3660_446D_A982_578706EA07E5

#include "Pricable.h"
#include <vector>

class PricePathDependentPricable : public Pricable {
public:
    PricePathDependentPricable(float32_t expiryTime) : Pricable(expiryTime) {}
    virtual ~PricePathDependentPricable();
    virtual float32_t payoff(std::vector<float32_t> prices) const = 0;
};

#endif /* E4B41828_3660_446D_A982_578706EA07E5 */
