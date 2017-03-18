/**
    @file       SysTick.c
    @brief      Function library for the SysTick timer
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h"  
#include "SysTick.h"

/**
    @brief      Configures the SysTick timer to generate interrupts every milisecond
    @param      None
    @return     NO_ERROR if function executes successfully
                SYSTICK_INITIALISATION_ERROR if an initialisation error occurs
*/
enum ErrorType ConfigureSysTick(void)
{
	if(SysTick_Config(SystemCoreClock / 1000) != 0)
	{
		return SYSTICK_INITIALISATION_ERROR;
	}
	
	return NO_ERROR;
}

/*
Description:	Creates a configurable delay using the SysTick timer interrupt
Parameters:		Time - Length of delay (ms)
Returns:			-
*/
void SysTick_Handler(void)
{
	if(TimeDelay != 0)
	{
		TimeDelay--;
	}
}

/*
Inputs: N/A
Outputs: N/A
Purpose: Timer, decrements the TimeDelay variable for the Delay() function
Author: Found in one of the STM32 SPL example files
*/

void Delay(__IO uint32_t Time)
{
	TimeDelay = Time;
	while(TimeDelay != 0);
}
