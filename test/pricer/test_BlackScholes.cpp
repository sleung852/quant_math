#include "gtest/gtest.h"
#include "../../pricer/BlackScholes.h"
#include "../../options/EuropeanOption.h"

TEST(BlackScholesTest, testd1) {
    float32_t result = BlackScholes().d1(100, 100, 0.05, 0.02, 1);
    EXPECT_NEAR(result, 2.51, 0.01);
}

TEST(BlackScholesTest, testd2) {
    EuropeanOption put_option(1, 100, false);
    float32_t result = BlackScholes().d2(100, 100, 0.05, 0.02, 1);
    EXPECT_NEAR(result, 2.49, 0.01);
}

TEST(BlackScholesTest, testCallPrice) {
    EuropeanOption call_option(1, 100, true);
    float32_t result = BlackScholes().price(call_option, 100, 0.05, 0.2);
    EXPECT_NEAR(result, 10.45058357, 0.0001);
}

TEST(BlackScholesTest, testPutPrice) {
    EuropeanOption put_option(1, 100, false);
    float32_t result = BlackScholes().price(put_option, 100, 0.05, 0.2);
    EXPECT_NEAR(result, 5.573526022, 0.0001);
}

TEST(BlackScholesTest, testCallDelta) {
    EuropeanOption call_option(1, 100, true);
    float32_t result = BlackScholes().delta(call_option, 100, 0.05, 0.2);
    EXPECT_NEAR(result, 0.64, 0.01);
}

TEST(BlackScholesTest, testPutDelta) {
    EuropeanOption put_option(1, 100, false);
    float32_t result = BlackScholes().delta(put_option, 100, 0.05, 0.2);
    EXPECT_NEAR(result, -0.36, 0.01);
}
