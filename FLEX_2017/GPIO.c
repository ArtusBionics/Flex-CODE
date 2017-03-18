/**
    @file       GPIO.c
    @brief      Function library for GPIO pin initialisation
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h" 
#include "GPIO.h"

/**
    @brief      Configures the GPIO pins according to the pin assignments defined in GPIO.h
    @param      None
    @return     None
*/
void ConfigureGPIO(void)
{
    GPIO_InitTypeDef GPIO_InitStruct;										//GPIO init structure
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE); 				    //Enable clock to GPIOA pins
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); 					//Enable clock to GPIOB pins
	
    GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
    
    // Configure Status LEDs: output mode, open drain, 2MHz frequency 
 	GPIO_InitStruct.GPIO_Pin = STATUS_R_PIN | STATUS_G_PIN | STATUS_B_PIN;
 	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;										
 	GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;							
 	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
 	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
 	GPIO_Init(GPIOA, &GPIO_InitStruct);
 	
 	// Initialize status LED to be OFF
 	GPIO_WriteBit(GPIOA, STATUS_B_PIN, Bit_SET);
 	GPIO_WriteBit(GPIOA, STATUS_R_PIN, Bit_SET);
 	GPIO_WriteBit(GPIOA, STATUS_G_PIN, Bit_SET);
 	
 	// Configure Primary Encoder Pins on TIM2: alternate function, push-pull, 2MHz frequency
 	GPIO_InitStruct.GPIO_Pin = PRIM_APPS_A_PIN	 | PRIM_APPS_B_PIN	;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
 	
 	GPIO_PinAFConfig(GPIOA, PRIM_APPS_A_PINSOURCE, GPIO_AF_2);
 	GPIO_PinAFConfig(GPIOA, PRIM_APPS_B_PINSOURCE, GPIO_AF_2);
 	
 	// Configure Secondary Encoder Pins on TIM3: alternate function, push-pull, 2MHz frequency
 	GPIO_InitStruct.GPIO_Pin = SEC_APPS_A_PIN | SEC_APPS_B_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStruct);
    
    GPIO_PinAFConfig(GPIOB, SEC_APPS_A_PINSOURCE, GPIO_AF_1);
 	GPIO_PinAFConfig(GPIOB, SEC_APPS_B_PINSOURCE, GPIO_AF_1);

    // Configure Hall Effect Pins on TIM16/17 (WHEELS): alternate function, 2MHz, push-pull
//    GPIO_InitStruct.GPIO_Pin =  RIGHT_WHEEL_SPEED_PIN;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);
    
//    GPIO_InitStruct.GPIO_Pin =  LEFT_WHEEL_SPEED_PIN;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);   
    
//    GPIO_PinAFConfig(GPIOA, RIGHT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM16 pins to AF2
//    GPIO_PinAFConfig(GPIOA, LEFT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM17 pins to AF2

    // Configure Brake Input Pin: input mode, push-pull, 2MHz frequency
 	GPIO_InitStruct.GPIO_Pin = BRAKE_IN_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
 
    // Configure ADC Pins: analog input mode, no pull up or pull down
 	GPIO_InitStruct.GPIO_Pin = STEERING_ANGLE_PIN ;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    //Configure GPIO pins for CAN
    GPIO_InitStruct.GPIO_Pin = CAN_TX | CAN_RX;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;                                        
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;                            
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &GPIO_InitStruct);
}
