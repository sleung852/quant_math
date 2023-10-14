#ifndef A55E457A_BF22_4B77_90A8_D1439A879BA0
#define A55E457A_BF22_4B77_90A8_D1439A879BA0

#include "arm_neon.h"

class Pricable {
protected:
    float32_t expiryTime;

public:

    Pricable(float32_t expiryTime) : expiryTime(expiryTime) {}
    virtual ~Pricable() {}

    float32_t getExpiryTime() const {
        return expiryTime;
    }
};

#endif /* A55E457A_BF22_4B77_90A8_D1439A879BA0 */
