//
// Created by See Leung on 3/10/2023.
//

#ifndef QUANT_MATH_GEOMETRICBROWNIANMOTION_H
#define QUANT_MATH_GEOMETRICBROWNIANMOTION_H

#include "GeometricBrownianMotionPricer.h"


class DiscreteAssetModelPricer : public GeometricBrownianMotionPricer {
public:

    DiscreteAssetModelPricer(float32_t drift, float32_t volatility);

    std::vector<float32_t> generateRiskNeutralPricePath(float32_t toDate, int nSteps, bool dir = true) override;
};


#endif //QUANT_MATH_GEOMETRICBROWNIANMOTION_H
