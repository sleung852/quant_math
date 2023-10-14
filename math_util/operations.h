//
// Created by See Leung on 26/9/2023.
//

#ifndef QUANT_MATH_OPERATIONS_H
#define QUANT_MATH_OPERATIONS_H

#include <concepts>
#include <vector>
#include <cmath>
#include "../common.h" // https://arm-software.github.io/acle/neon_intrinsics/advsimd.html

//template <typename T>
//concept numeric = std::floating_point<T> or std::integral<T>;

class operations {
public:
    static float32_t sumArray(float32_t* data, int size) {
        float32x4_t sumVector = vdupq_n_f32(0.0f);

        int numIterations = size / 4;

        for (int i = 0; i < numIterations; i++) {
            float32x4_t vector = vld1q_f32(data);
            sumVector = vaddq_f32(sumVector, vector);
            data += 4;
        }
        float32x2_t sum2 = vadd_f32(vget_low_f32(sumVector), vget_high_f32(sumVector));
        float32x2_t sum = vpadd_f32(sum2, sum2);
        float32_t result = vget_lane_f32(sum, 0);
        for (int i = 0; i < numIterations % 4; i++) {
            result += *data++;
        }

        return result;
    }

    static float32_t sumArray(std::vector<float32_t> data) {
        return sumArray(data.data(), data.size());
    }

    static float32_t mean(float32_t* data, int size) {
        float32_t sum_value = sumArray(data, size);
        return sum_value / size;
    }

    static float32_t mean(std::vector<float32_t> data) {
        return mean(data.data(), data.size());
    }

    static float32_t standardDeviation(float32_t* data, int size) {
        float32x4_t sumVector = vdupq_n_f32(0.0f);
        float32_t mu = mean(data, size);
        float32x4_t mus = vdupq_n_f32(mu);
        int numIterations = size / 4;
        for (int i = 0; i < numIterations; i++) {
            float32x4_t vector = vld1q_f32(data);
            float32x4_t x_minus_mu = vsubq_f32(vector, mus);
            sumVector = vmlaq_f32(sumVector, x_minus_mu, x_minus_mu);
            data += 4;
        }
        float32x2_t sum2 = vadd_f32(vget_low_f32(sumVector), vget_high_f32(sumVector));
        float32x2_t sum = vpadd_f32(sum2, sum2);
        float32_t result = vget_lane_f32(sum, 0);
        for (int i = 0; i < numIterations % 4; i++) {
            result += (*data - mu) * (*data - mu);
            data++;
        }
        return sqrt(result / size);
    }

};


#endif //QUANT_MATH_OPERATIONS_H
