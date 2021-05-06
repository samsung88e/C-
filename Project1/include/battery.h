#ifndef BATTERY_H_
#define BATTERY_H_
#include "entity_base.h"

namespace csci3081 {

class Battery {
public:
    Battery(float charge, float chargeSize, float chargeRate, float dechargeRate);
    void Charge();
    void Decharge();
    float GetCharge();

private:
    float charge;
    float chargeSize;
    float chargeRate;
    float dechargeRate;
};

}

#endif