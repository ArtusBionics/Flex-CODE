/**
    @file       Interrupt.c
    @brief      Function library for Interrupt initialisation and ISRs
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h" 
#include "stm32f0xx_it.h"
#include "Interrupt.h"



/**
    @brief      Configures the Interrupts according to the way they are defined in it.h
    @param      None
    @return     None
*/
void ConfigureInterrupt(void) 
{
		NVIC_InitTypeDef NVIC_InitStructure;
		
		/* TIM2 Interrupt enable */
		TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
		/* Enable the TIM3 gloabal Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
		
		/* TIM3 Interrupt enable */
		TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
		/* Enable the TIM3 gloabal Interrupt */
		NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
		NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
		NVIC_Init(&NVIC_InitStructure);
		
//	/* Enable the TIM1 global Interrupt, priority 1 */
//		NVIC_InitStructure.NVIC_IRQChannel = TIM16_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//		NVIC_Init(&NVIC_InitStructure);
//		
//       /* Enable the FRWSS Channel 1 Interrupt Request */
//		TIM_ITConfig(TIM16, TIM_IT_CC1, ENABLE);
//				
//		/* Enable the TIM1 global Interrupt, priority 1 */
//		NVIC_InitStructure.NVIC_IRQChannel = TIM17_IRQn;
//		NVIC_InitStructure.NVIC_IRQChannelPriority = 1;
//		NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//		NVIC_Init(&NVIC_InitStructure);
//        
//       /* Enable the FLWSS Channel 1 Interrupt Request */
//		TIM_ITConfig(TIM17, TIM_IT_CC1, ENABLE);
//       
//        TIM_Cmd(TIM17, ENABLE);	
}


