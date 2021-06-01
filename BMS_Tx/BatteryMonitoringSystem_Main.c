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
#include <conio.h>
#include <ctype.h>
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

#ifndef UNIT_TEST   	
int main()
{
	int count_of_Entries;
	   int ch;

   _cputs( "No of entries " );

      ch = _getwch();
      printf("got %d\n", ch);
   
	
	
	Battery_Monitoring_System_main(1500);
	
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
