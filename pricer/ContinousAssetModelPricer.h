#ifndef B43985CF_8F8D_4505_B3C2_EA0BE9D8CD0F
#define B43985CF_8F8D_4505_B3C2_EA0BE9D8CD0F

#include "GeometricBrownianMotionPricer.h"


class ContinuousAssetModelPricer : public GeometricBrownianMotionPricer {
public:
    ContinuousAssetModelPricer(float32_t drift, float32_t volatility);
    std::vector<float32_t> generateRiskNeutralPricePath(float32_t toDate, int nSteps, bool dir = true) override;
};


#endif /* B43985CF_8F8D_4505_B3C2_EA0BE9D8CD0F */
