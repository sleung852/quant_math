#include "gtest/gtest.h"
#include "../../options/EuropeanOption.h"

TEST(EuropeanOptionsTest, isPut) {
    EuropeanOption put_option(1, 100, false);
    ASSERT_FALSE(put_option.isCall());
}

TEST(EuropeanOptionsTest, isCall) {
    EuropeanOption call_option(1, 100, true);
    ASSERT_TRUE(call_option.isCall());
}

TEST(EuropeanOptionsTest, getStrike) {
    EuropeanOption call_option(1, 100, true);
    ASSERT_EQ(call_option.getStrikePrice(), 100);
}

TEST(EuropeanOptionsTest, getExpiryTime) {
    EuropeanOption call_option(1, 100, true);
    ASSERT_EQ(call_option.getExpiryTime(), 1);
}

TEST(EuropeanOptionsTest, putPayOffInMoney) {
    EuropeanOption put_option(1, 100, false);
    ASSERT_EQ(put_option.payoff(80), 20);
}

TEST(EuropeanOptionsTest, putPayOffOutMoney) {
    EuropeanOption put_option(1, 100, false);
    ASSERT_EQ(put_option.payoff(110), 0.0);
}

TEST(EuropeanOptionsTest, callPayOfInMoney) {
    EuropeanOption call_option(1, 100, true);
    ASSERT_EQ(call_option.payoff(110), 10);
}

TEST(EuropeanOptionsTest, callPayOffOutMoney) {
    EuropeanOption call_option(1, 100, true);
    ASSERT_EQ(call_option.payoff(90), 0.0);
}