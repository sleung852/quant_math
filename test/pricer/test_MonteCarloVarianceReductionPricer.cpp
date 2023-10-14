//
// Created by Leung See Ho on 14/10/2023.
//
//
// Created by See Leung on 13/10/2023.
//

#include "gtest/gtest.h"
#include "../../pricer/BlackScholes.h"
#include "../../pricer/MonteCarloVarianceReductionPricer.h"
#include "../../pricer/ContinousAssetModelPricer.h"
#include "../../options/EuropeanOption.h"

TEST(MonteCarloPricerVarianceReductionTest, testEuropeanCallPrice) {
    EuropeanOption call_option(20, 120, true);
    float32_t bs_result = BlackScholes().price(call_option, 100, 0.0, 0.05);
    ContinuousAssetModelPricer asset_model(100, 0.05);
    MonteCarloVarianceReductionPricer mc_pricer;
    float32_t mc_result = mc_pricer.price(call_option, asset_model);
    EXPECT_NEAR(bs_result, mc_result, 0.01);
}

TEST(MonteCarloPricerVarianceReductionTest, testEuropeanPutPrice) {
    EuropeanOption put_option(20, 120, false);
    float32_t bs_result = BlackScholes().price(put_option, 100, 0.0, 0.05);
    ContinuousAssetModelPricer asset_model(100, 0.05);
    MonteCarloVarianceReductionPricer mc_pricer;
    float32_t mc_result = mc_pricer.price(put_option, asset_model);
    EXPECT_NEAR(bs_result, mc_result, 0.01);
}