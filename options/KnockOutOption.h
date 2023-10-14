//
// Created by See Leung on 11/10/2023.
//

#ifndef QUANT_MATH_KNOCKOUTOPTION_H
#define QUANT_MATH_KNOCKOUTOPTION_H

#include "PricePathDependentOption.h"

class KnockOutOption : public PricePathDependentOption {
public:
    KnockOutOption(float32_t expiryTime, float32_t strikePrice, bool isCall, float32_t barrier) : PricePathDependentOption(expiryTime, strikePrice, isCall), barrier(barrier) {}
    virtual ~KnockOutOption() {}

    float32_t getBarrier() const {
        return barrier;
    }

    void setBarrier(float32_t barrier_in) {
        barrier = barrier_in;
    }
private:
    float32_t barrier;
};


#endif //QUANT_MATH_KNOCKOUTOPTION_H
