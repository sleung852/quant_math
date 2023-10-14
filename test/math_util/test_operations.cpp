#include "gtest/gtest.h"
#include "../../math_util/operations.h"

TEST(OperationsTest, sumArray) {
    float32_t v[10] = {1,2,3,4,5,6,7,8,9,10};
    float32_t sum = operations::sumArray(v, 10);
    ASSERT_DOUBLE_EQ(55, sum);
}

TEST(OperationsTest, mean) {
    float32_t v[10] = {1,2,3,4,5,6,7,8,9,10};
    float32_t mu = operations::mean(v, 10);
    ASSERT_DOUBLE_EQ(5.5, mu);
}

TEST(OperationsTest, standardDeviation) {
    float32_t v[10] = {1,2,3,4,5,6,7,8,9,10};
    float32_t sd = operations::standardDeviation(v, 10);
    EXPECT_NEAR(2.872, sd, 0.01);
}