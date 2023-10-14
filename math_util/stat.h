//
// Created by See Leung on 26/9/2023.
//

#ifndef QUANT_MATH_STAT_H
#define QUANT_MATH_STAT_H

#include <functional>
#include <concepts>
#include <arm_neon.h>


// template <typename T>
// concept FloatingPoint = std::floating_point<T>;


class Stat {
public:
    static float32_t normcdf(float32_t x);
    static float32_t norminv(float32_t x);

    // template<FloatingPoint T>
    static float32_t integral(std::function<float32_t(float32_t)> fn , int a, int b, int n) {
        float32_t est = 0;
        float32_t h = (b - a) / n;
        for (unsigned int i = 0; i < n; i++) {
            est += fn(a + i * h + 0.5 * h) / n;
        }
        return est;
    }

    static std::vector<float32_t> randn(size_t n);

    static float32_t randuniform();


};


#endif //QUANT_MATH_STAT_H
