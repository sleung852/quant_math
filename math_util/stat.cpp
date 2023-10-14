//
// Created by See Leung on 26/9/2023.
//

#include "stat.h"
#include <cmath>
#include <vector>
#include "cstdlib"

float32_t Stat::normcdf(float32_t x) {
    if (x >= 0) {
        float32_t k = 1 / (1 + 0.2316419 * x);
        return  1 - 1 / (sqrt(2 * M_PI)) * exp(-(x*x) / 2) * k *(0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
    }
    return 1 - normcdf(-x);
}

// series of horner functions
static float32_t hornerFn(float32_t x, float32_t a0) {
    return a0;
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1) {
    return a0 + hornerFn(x, a1);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2) {
    return a0 + hornerFn(x, a1, a2);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3) {
    return a0 + hornerFn(x, a1, a2, a3);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3, float32_t a4) {
    return a0 + hornerFn(x, a1, a2, a3, a4);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3, float32_t a4, float32_t a5) {
    return a0 + hornerFn(x, a1, a2, a3, a4, a5);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3, float32_t a4, float32_t a5, float32_t a6) {
    return a0 + hornerFn(x, a1, a2, a3, a4, a5, a6);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3, float32_t a4, float32_t a5, float32_t a6, float32_t a7) {
    return a0 + hornerFn(x, a1, a2, a3, a4, a5, a6, a7);
}

static float32_t hornerFn(float32_t x, float32_t a0, float32_t a1, float32_t a2, float32_t a3, float32_t a4, float32_t a5, float32_t a6, float32_t a7, float32_t a8) {
    return a0 + hornerFn(x, a1, a2, a3, a4, a5, a6, a7, a8);
}

static float32_t a0 = 2.50662823884;
static float32_t a1 = -18.61500062529;
static float32_t a2 = 41.39119773534;
static float32_t a3 = -25.44106049637;
static float32_t b1 = -8.47351093090;
static float32_t b2 = 23.08336743743;
static float32_t b3 = -21.06224101826;
static float32_t b4 = 3.13082909833;
static float32_t c0 = 0.3374754822726147;
static float32_t c1 = 0.9761690190917186;
static float32_t c2 = 0.1607979714918209;
static float32_t c3 = 0.0276438810333863;
static float32_t c4 = 0.0038405729373609;
static float32_t c5 = 0.0003951896511919;
static float32_t c6 = 0.0000321767881768;
static float32_t c7 = 0.0000002888167364;
static float32_t c8 = 0.0000003960315187;


// Using Moro algorithm
float32_t Stat::norminv(float32_t x) {

    float32_t y = x - 0.5;
    if (abs(y) < 0.42) {
        float32_t r = y * y;
        return y * hornerFn(r, a0, a1, a2, a3) / hornerFn(r, 1, b1, b2, b3, b4);
    }
    float32_t r;
    if (y < 0) r = x;
    else r = 1 - x;
    float32_t s = log(-log(r));
    float32_t t = hornerFn(s, c0, c1, c2, c3, c4, c5, c6, c7, c8);
    if (x > 0.5) return t;
    return -t;
}

float32_t Stat::randuniform() {
    return rand() / (float32_t) RAND_MAX;
}

std::vector<float32_t> Stat::randn(size_t n) {
    std::vector<float32_t> result(n, 0.0);
    for (size_t i = 0; i < n; i++) {
        result[i] = randuniform();
    }
    return result;
}




