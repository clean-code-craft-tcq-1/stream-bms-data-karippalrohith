/* ******************************************************************************
 ***     \file        BatteryMonitoringSystem_Main.h
 ***     \ingroup     Evaluation-TCQ
 ***     \author      Rohith K N
 ***
 ***     \brief       Header file for the module
 ***
 ***     \par         File_description
 ***                  This file have the declarations of the variables and methods of the module
 ***
 *****************************************************************************/
#ifndef BMS_H_
#define BMS_H_
/*=============================================================================
 =======                            INCLUDES                             =======
 ============================================================================*/
/*------ standard includes -------*/

/*------ module includes -------*/

#define BMS_PARAMETER_TEMP_MAX_VALUE	100
#define BMS_PARAMETER_TEMP_MIN_VALUE	0

#define BMS_PARAMETER_SOC_MAX_VALUE		150
#define BMS_PARAMETER_SOC_MIN_VALUE		50

typedef enum {
	TO_CONSOLE,
	TARGET_MAX
} BMS_Target_OP;

typedef enum {
	TEMP_CELCUIS,
	TEMP_MAX
}BMS_Temp_Unit;

typedef enum {
	PRINTED_IN_CONSOLE,
	NOT_PRINTED
}BMS_Target;

typedef struct {
	float Temperature;
	float SOC;
} BMS_Parameters_s;

typedef struct{
	void (*BMS_Target_OP)(BMS_Parameters_s BMS_Parameters_t);
}BMS_Send_Parameter_s;

typedef struct {
	float (*BMS_Temp_Unit)(void);
}BMS_Temp_Value_s;

typedef struct{
	int BMS_Parameters_Print_Status;
}BMS_Status_s;

BMS_Status_s Battery_Monitoring_System_Functionality(void);

int Battery_Monitoring_System_main(void);
BMS_Parameters_s Battery_Monitoring_System_Get_Input_Parameters(void);

float Battery_Monitoring_System_Get_Input_Parameter_Temperature_Celcuis(void);
float Battery_Monitoring_System_Get_Input_Parameter_SOC(void);

void sendToConsole(BMS_Parameters_s BMS_Parameters_t);
#endif /*BMS_H_*/
