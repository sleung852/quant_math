#ifndef FD8613DE_8B91_4CF4_9739_4F1C59196B35
#define FD8613DE_8B91_4CF4_9739_4F1C59196B35

#include "arm_neon.h"


class Option {
public:
    Option(float32_t strikePrice, bool isCall) : strikePrice(strikePrice), call(isCall) {}
    virtual ~Option() {}
    
    float32_t getStrikePrice() const {
        return strikePrice;
    }
    bool isCall() const {
        return call;
    }


protected:
    float32_t strikePrice;
    bool call;
};

#endif /* FD8613DE_8B91_4CF4_9739_4F1C59196B35 */
