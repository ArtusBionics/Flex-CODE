/*
Project:			FSM_2017-Code
File:					Timers.c
Description:	Function library for the CAN peripheral
Copyright 2016 UBC Formula Electric.
*/

#include "stm32f0xx.h" 
#include "Timers.h" 

/**
    @brief      Configures the Timers according to the method defined in tim.h
    @param      None
    @return     None
*/

void ConfigureTIM(void)
{	
//        TIM_ICInitTypeDef           TIM_ICInitStructure;
//        TIM_TimeBaseInitTypeDef     TIM_TimeBaseInitStructure;
    
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);    // Enable peripheral clock to TIM2
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);    // Enable peripheral clock to TIM3
//        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16, ENABLE);   // Enable peripheral clock to TIM16
//        RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);   // Enable peripheral clock to TIM17
        
		//Configure TIM2 in encoder interface mode for P-APPS
	//	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);	
	//	TIM_SetAutoreload(TIM2, 0xFFFF);
 //       TIM_Cmd(TIM2, ENABLE);																						// Enable TIM2

		//Configure TIM3 in encoder interface mode for P-APPS
	//	TIM_EncoderInterfaceConfig(TIM3, TIM_EncoderMode_TI12, TIM_ICPolarity_Rising, TIM_ICPolarity_Rising);
	//	TIM_SetAutoreload(TIM3, 0xFFFF);
   //     TIM_Cmd(TIM3, ENABLE);																						// Enable TIM3
        
        //Reset Counters
        TIM_SetCounter(TIM2, 0);
        TIM_SetCounter(TIM3, 0);
    
		//Configures TIM16 for FR hall effect sensors in Input Capture Mode         
//        TIM_TimeBaseInitStructure.TIM_Prescaler = 0x0001;               // Max. prescaler gives us TIM clock = 30 Hz (if original TIM clock was at 2MHz)
//        TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//        TIM_TimeBaseInitStructure.TIM_Period = 0xFFFF;                   // In upcounting mode, the counter will reset after rolling over this value (Value in Auto Reload Register)
//        TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // Set clock division to 1... FOR NOW
//        TIM_TimeBaseInit(TIM16, &TIM_TimeBaseInitStructure);
    
//		TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;									//External Signal is connected to TIM16 CH1 pin (PA_12)
//		TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;				//Sets Rising edge as the active edge			
//		TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;		//Timer Input 1 is connected to Timer IC1
//		TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;							//Capture performed each time event takes place
//		TIM_ICInitStructure.TIM_ICFilter = 0x0;														//No filtering needed for our application
//		TIM_ICInit(TIM16, &TIM_ICInitStructure);
//
//        TIM_Cmd(TIM16, ENABLE);																						//Timer Enable Counter
//
//		//Configures TIM17 for FL hall effect sensors in Input Capture Mode
//		TIM_TimeBaseInitStructure.TIM_Prescaler = 0x0001;               // Max. prescaler gives us TIM clock = 30 Hz (if original TIM clock was at 2MHz)
//        TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//        TIM_TimeBaseInitStructure.TIM_Period = 0x0;                   // In upcounting mode, the counter will reset after rolling over this value (Value in Auto Reload Register)
//        TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;     // Set clock division to 1... FOR NOW
//        TIM_TimeBaseInit(TIM17, &TIM_TimeBaseInitStructure);
//            
//        TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;									//External Signal is connected to TIM17 CH1 pin (PA_13)
//		TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;				//Sets Rising edge as the active edge
//		TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;		//Timer Input 1 is connected to Timer IC1
//		TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;							//Capture performed each time event takes place
//		TIM_ICInitStructure.TIM_ICFilter = 0x0;														//No filtering needed for our application
//		TIM_ICInit(TIM17, &TIM_ICInitStructure);
//        
//        TIM_Cmd(TIM17, ENABLE);																						//Timer Enable Counter
}
