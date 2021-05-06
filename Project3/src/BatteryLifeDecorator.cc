#include "BatteryLifeDecorator.h"


namespace csci3081 {

void BatteryLifeDecorator::MoveToPoints(float dt) {
    
    entity->MoveToPoints(dt);

    Battery* battery = entity->GetBattery();
    
    picojson::object obj = entity->GetObject();

    picojson::value val = obj["color"];
    
    float BatteryPercentage = battery->GetCharge() / battery->GetChargeSize();

    if(!isGreen){
        UpdateColor("58D68D");
        isGreen = true;
    }
    else if(entity->IsBatteryEmpty() && !isRed){
        UpdateColor("FF0000");
        isRed = true;
    }

    /*if(BatteryPercentage > 0.75 && val.serialize() != "0x58D68D"){
        UpdateColor("58D68D"); //green
        color = 1;
    }
    else if(BatteryPercentage > 0.50 && color != 2){
        UpdateColor("FFFF00"); //yellow
        color = 2;
    }
    else if(BatteryPercentage > 0.25 && color != 3){
        UpdateColor("FFA500"); // orange
        color = 3;
    }
    else if(BatteryPercentage > 0.1 && color != 4){
        UpdateColor("FF0000"); // red
        color = 4;
    }
    else if(BatteryPercentage <= 0.001 && color != 5){
        UpdateColor("000000"); // black
        color = 5;
    }*/
    
}

void BatteryLifeDecorator::UpdateColor(std::string color) {
  AEntitySubject* entitySubject = entity->GetSubject();
  picojson::value val;
  std::string json = "{\"details\": {\"color\": \"" + color + "\"},\"type\": \"notify\", \"value\": \"updateDetails\"}";
  picojson::parse(val, json);
  IEntity* ent = dynamic_cast<IEntity*>(entity);
  entitySubject->Notify(val, *ent);
}

}
