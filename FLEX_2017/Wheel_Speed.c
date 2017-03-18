/**
    @file       Main.c
    @brief      Main source code for FSM_2017
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h"                  // Device header


/**
* @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
}


void WS_Config(void) 
{
    /*************** GPIO CONFIGURATION *******************/
    GPIO_InitTypeDef GPIO_InitStruct;
    
    GPIO_InitStruct.GPIO_Pin =  RIGHT_WHEEL_SPEED_PIN | LEFT_WHEEL_SPEED_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
 
     GPIO_PinAFConfig(GPIOA, RIGHT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM16 pins to AF2
     GPIO_PinAFConfig(GPIOA, LEFT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM17 pins to AF2
    /*************** GPIO CONFIGURATION *******************/
    
    
    
    /*************** TIM CONFIGURATION ********************/
    
    // Configure TIM16/17 for wheel speed hall effect sensors:
    TIM_ICInitTypeDef  TIM_ICInitStructure;
    
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICFilter = 0x0;

    TIM_ICInit(TIM16, &TIM_ICInitStructure);
    TIM_ICInit(TIM17, &TIM_ICInitStructure);
  
    /* TIM enable counter */
    TIM_Cmd(TIM16, ENABLE);
    TIM_Cmd(TIM17, ENABLE);
    
    /*************** TIM CONFIGURATION ********************/
}