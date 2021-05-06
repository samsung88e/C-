#include "battery.h"


namespace csci3081 {


Battery::Battery(float charge, float chargeSize, float chargeRate, float dechargeRate) {
    this->charge = charge;
    this->chargeSize = chargeSize;
    this->chargeRate = chargeRate;
    this->dechargeRate = dechargeRate;
}


void Battery::Charge(float dt) {
    if (charge < chargeSize) {
        charge += dt * chargeRate;
    }
    return;
}

void Battery::Decharge(float dt) {
    if (charge > 0.001f) {
        charge -= dt * dechargeRate;
    }
    else {
        charge = 0.f;
    }
    return;
}

void Battery::SetCharge(float charge) {
    this->charge = charge;
}

float Battery::GetCharge() {
    return charge;
}

void Battery::SetChargeSize(float chargeSize) {
    this->chargeSize = chargeSize;
}

float Battery::GetChargeSize() {
    return chargeSize;
}

}
