/* ******************************************************************************
 ***
 ***     \file        BatteryMonitoringSystem_Main.c
 ***     \ingroup     Assessment-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file for Battery Monitoring System
 ***
 ***     \par         File_description
 ***                  This file explores more about functions
 ***
 *****************************************************************************/
 
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/
#include <stdio.h>

/*------ module includes --------*/
#include "BatteryMonitoringSystem_Main.h"

/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 ==============================================================================*/

/*=============================================================================
 =======                              METHODS                            =======
 =============================================================================*/

ifndef -DUNIT_TEST
int main()
{
	Battery_Monitoring_System_main(10);
	return 0;
}
#endif

BMS_Status_s Battery_Monitoring_System_main(int count)
{
	int i = 0;
	BMS_Status_s BMS_Status;
	
	for(i=0;i<count;i++)
	{
		BMS_Status = Battery_Monitoring_System_Functionality();
	}
	return BMS_Status;
}
