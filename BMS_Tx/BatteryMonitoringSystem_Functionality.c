/* ******************************************************************************
 ***
 ***     \file        BatteryMonitoringSystem_Input.c
 ***     \ingroup     Assessment-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Main file for Battery Monitoring
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
#include <stdlib.h>

/*------ module includes --------*/
#include "BatteryMonitoringSystem_Main.h"

BMS_Send_Parameter_s BMS_Send_Parameter[1] = {sendToConsole};
BMS_Temp_Value_s BMS_Temp_Value[1] = {Battery_Monitoring_System_Get_Input_Parameter_Temperature_Celcuis};

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

void Battery_Monitoring_System_Functionality(void)
{
	BMS_Parameters_Print_Status = NOT_PRINTED;
	BMS_Parameters_s BMS_Parameters_Values = {0,0};
	
	//Get the values
	BMS_Parameters_Values = Battery_Monitoring_System_Get_Input_Parameters();
	
	//Process the values
	
	//Output the values	
	BMS_Send_Parameter[0].BMS_Target_OP(BMS_Parameters_Values);
}

BMS_Parameters_s Battery_Monitoring_System_Get_Input_Parameters(void)
{
	
	BMS_Parameters_s BMS_Parameters = {0,0};
	
	BMS_Parameters.Temperature = BMS_Temp_Value[0].BMS_Temp_Unit();
	BMS_Parameters.SOC = Battery_Monitoring_System_Get_Input_Parameter_SOC();
	
	return BMS_Parameters;
}


float Battery_Monitoring_System_Get_Input_Parameter_Temperature_Celcuis(void)
{
	float temp;
	
	temp = (rand() % (BMS_PARAMETER_TEMP_MAX_VALUE - BMS_PARAMETER_TEMP_MIN_VALUE + 1)) + BMS_PARAMETER_TEMP_MIN_VALUE;
	
	return temp;
}

float Battery_Monitoring_System_Get_Input_Parameter_SOC(void)
{
	float SOC;
	
	SOC = (rand() % (BMS_PARAMETER_SOC_MAX_VALUE - BMS_PARAMETER_SOC_MIN_VALUE + 1)) + BMS_PARAMETER_SOC_MIN_VALUE;
	
	return SOC;	
}

void sendToConsole(BMS_Parameters_s BMS_Parameters_t)
{
	printf("\nTemperature::%0.2f,SOC::%0.2f\n",BMS_Parameters_t.Temperature,BMS_Parameters_t.SOC); 
	BMS_Parameters_Print_Status = PRINTED_IN_CONSOLE;
}
