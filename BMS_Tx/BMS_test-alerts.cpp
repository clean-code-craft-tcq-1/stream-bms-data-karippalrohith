#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../test/catch.hpp"
#include "BatteryMonitoringSystem_Main.h"

TEST_CASE("Check if value is successfully send to cnsole for printing") {
	
	BMS_Status_s Alert_Status_Output = {NOT_PRINTED};
	
	//Alert_Status_Output = checkAndAlert(TO_CONTROLLER, batteryCharacter, 20);
	//REQUIRE(Alert_Status_Output.Alert_Print_Status == PRINTED_IN_CONTROLLER);
	//REQUIRE(Alert_Status_Output.breachType == NORMAL);
}
