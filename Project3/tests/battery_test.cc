#include "gtest/gtest.h"
#include <EntityProject/project_settings.h>
#include "../include/battery.h"
#include <EntityProject/entity.h>
#include "json_helper.h"

#include <iostream>
using std::string;

namespace csci3081 {

class BatteryTest : public ::testing::Test {
 protected:
  virtual void SetUp() {}
  virtual void TearDown() {}
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

TEST_F(BatteryTest, BatteryConstructor) {
	Battery battery = Battery();
	ASSERT_TRUE(battery.GetCharge() == 10000.f);
	ASSERT_TRUE(battery.GetChargeSize() == 10000.f);
}
TEST_F(BatteryTest, ChargeBattery){
	Battery battery = Battery(0, 10000, 1, 1);
	battery.Charge(50);
	ASSERT_TRUE(battery.GetCharge() == 50);
}
TEST_F(BatteryTest, DechargeBattery){
	Battery battery = Battery();
	battery.Decharge(1000);
	ASSERT_TRUE(battery.GetCharge() == 9000);
}
TEST_F(BatteryTest, GetSetCharge){
	Battery battery = Battery();
	battery.SetCharge(84);
	ASSERT_TRUE(battery.GetCharge() == 84);
}
TEST_F(BatteryTest, GetSetChargeSize){
	Battery battery = Battery();
	battery.SetChargeSize(2000);
	ASSERT_TRUE(battery.GetChargeSize() == 2000);
}


}  // namespace csci3081
