#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "BatteryMonitoringSystem_Main.h"

TEST_CASE("Check if temp in celcuis and SOC is being updated") {
	
	BMS_Parameters_s BMS_Parameters = {0,0};
	BMS_Parameters = Battery_Monitoring_System_Get_Input_Parameters();
	REQUIRE(BMS_Parameters.Temperature  != 0);
	REQUIRE(BMS_Parameters.SOC   != 0);
}

TEST_CASE("Check if value is successfully send to console for printing") {
	
	BMS_Status_s BMS_Status = {NOT_PRINTED};
	BMS_Status = Battery_Monitoring_System_Functionality();
	REQUIRE(BMS_Status.BMS_Parameters_Print_Status == PRINTED_IN_CONSOLE);
}
