//
// Created by See Leung on 26/9/2023.
//

#include "BlackScholes.h"

float32_t BlackScholes::price(EuropeanOption& option, float32_t S, float32_t r, float32_t sigma) {
    return price(S, option.getStrikePrice(), r, sigma, option.getExpiryTime(), option.isCall());
}

float32_t BlackScholes::delta(EuropeanOption& option, float32_t S, float32_t r, float32_t sigma, float32_t h) {
    float32_t high_price = price(S + h, option.getStrikePrice(), r, sigma, option.getExpiryTime(), option.isCall());
    float32_t low_price = price(S - h, option.getStrikePrice(), r, sigma, option.getExpiryTime(), option.isCall());
    return (high_price-low_price) / (2.0 * h);
}

float32_t BlackScholes::price(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T, bool isCall) {
    float32_t d1_v = d1(S, K, r, sigma, T);
    float32_t d2_v = d2(S, K, r, sigma, T);
    if (isCall) {
        return S * Stat::normcdf(d1_v) - K * exp(-r * T) * Stat::normcdf(d2_v);
    } else {
        return K * exp(-r * T) * Stat::normcdf(-d2_v) - S * Stat::normcdf(-d1_v);
    }
}

float32_t BlackScholes::d1(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T) {
    return (log(S / K) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
}

float32_t BlackScholes::d2(float32_t S, float32_t K, float32_t r, float32_t sigma, float32_t T) {
    return d1(S, K, r, sigma, T) - (sigma * sqrt(T));
}