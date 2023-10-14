//
// Created by See Leung on 26/9/2023.
//

#include "gtest/gtest.h"
#include "../../math_util/stat.h"

TEST(StatTest, normcdf_simple_example) {
    double test_value = 0.3;
    EXPECT_LT(Stat::normcdf(test_value), 1.0);
    EXPECT_GT(Stat::normcdf(test_value), 0.0);
}

TEST(StatTest, normcdf_small_value) {
    double test_value = -1e10;
    EXPECT_NEAR(Stat::normcdf(test_value), 0.0, 0.001);
}

TEST(StatTest, normcdf_large_value) {
    double test_value = 1e10;
    EXPECT_NEAR(Stat::normcdf(test_value), 1, 0.001);
}

TEST(StatTest, normcdf_increasing) {
    double test_value1 = 0.1;
    double test_value2 = 0.2;
    EXPECT_GT(Stat::normcdf(test_value2), Stat::normcdf(test_value1));
}

TEST(StatTest, normcdf_symmetry) {
    double test_value = 0.1;
    EXPECT_NEAR(Stat::normcdf(test_value), 1 - Stat::normcdf(- test_value), 0.0001);
}

TEST(StatTest, normcdf_zero) {
    double test_value = 0.0;
    EXPECT_DOUBLE_EQ(Stat::normcdf(test_value), 0.5);
}

TEST(StatTest, normcdf_norminv) {
    double test_value = 0.0;
    EXPECT_DOUBLE_EQ(Stat::norminv(Stat::normcdf(test_value)), test_value);
}

TEST(StatTest, normcdf_wellknown) {
    double test_value = 1.96;
    EXPECT_NEAR(Stat::normcdf(test_value), 0.975, 0.001);
}

float32_t test_fn(float32_t x) {
    return 3*x*x;
}

TEST(StatTest, integral) {
    double result = Stat::integral(test_fn, 1, 2, 100);
    EXPECT_NEAR(result, 3, 0.001);
}
