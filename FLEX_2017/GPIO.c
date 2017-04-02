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
  GPIO_InitTypeDef GPIO_InitStruct;																		//GPIO init structure
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE); 				    //Enable clock to GPIOA pins
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE); 						//Enable clock to GPIOB pins
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE) ;					//Enable clock to GPIOC pins
		RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE) ;					//Enable clock to GPIOD pins
	
  GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOC);
	GPIO_DeInit(GPIOD);
    
  // Configure Status LEDs: output mode, open drain, 2MHz frequency 
 	GPIO_InitStruct.GPIO_Pin = STATUS_R_PIN | STATUS_G_PIN | STATUS_B_PIN;
 	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;										
 	GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;							
 	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
 	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
 	GPIO_Init(GPIOC, &GPIO_InitStruct);
 	
 	// Initialize status LED to be OFF
 	GPIO_WriteBit(GPIOC, STATUS_B_PIN, Bit_SET);
 	GPIO_WriteBit(GPIOC, STATUS_R_PIN, Bit_SET);
 	GPIO_WriteBit(GPIOC, STATUS_G_PIN, Bit_SET);
	
	// Configure Fans: output mode, push-pull, 2MHz frequency
	GPIO_InitStruct.GPIO_Pin = FAN_1 | FAN_2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	// Configure Thumb: output mode, push-pull, 2MHz frequency 
	//GPIOF Ports
	GPIO_InitStruct.GPIO_Pin = THUMB_FLEX_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	//GPIOA Ports
	GPIO_InitStruct.GPIO_Pin = THUMB_EXT_1 | THUMB_FLEX_2 | THUMB_EXT_2 | THUMB_FLEX_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//GPIOC PORTS
	GPIO_InitStruct.GPIO_Pin = THUMB_EXT_3 | THUMB_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//GPIOB PORTS
	GPIO_InitStruct.GPIO_Pin = THUMB_AD;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	//Configure Index: Output mode, push-pull, 2 MHz frequency
	//GPIOB
	GPIO_InitStruct.GPIO_Pin = INDEX_AB | INDEX_AD | INDEX_EXT_1 | INDEX_EXT_2 | INDEX_EXT_3 | INDEX_FLEX_1 | INDEX_FLEX_2 | INDEX_FLEX_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	//Configure Middle: Output mode, push-pull, 2MHz frequency
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = MIDDLE_FLEX_1 | MIDDLE_EXT_1 | MIDDLE_FLEX_2 | MIDDLE_EXT_2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = MIDDLE_FLEX_3 | MIDDLE_EXT_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//Configure Ring: Output mode, push-pull, 2MHz frequency
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = RING_FLEX_1 | RING_EXT_1 | RING_FLEX_2 | RING_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//GPIOF
	GPIO_InitStruct.GPIO_Pin = RING_EXT_2 | RING_FLEX_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = RING_AD;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	//Configure Pinky: output mode, push-pull, 2MHz frequency
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = PINKY_FLEX_1 | PINKY_EXT_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	//GPIOD
	GPIO_InitStruct.GPIO_Pin = PINKY_FLEX_2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOD, &GPIO_InitStruct);
	//GPIOB
	GPIO_InitStruct.GPIO_Pin = PINKY_EXT_2 | PINKY_FLEX_3 | PINKY_EXT_3 | PINKY_AD | PINKY_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	//Configure Battery Status Monitor: Input mode, push-pull, 2MHz frequency
	GPIO_InitStruct.GPIO_Pin = BATTERY_STATUS;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//Configure Buttons
	//GPIOC
//	GPIO_InitStruct.GPIO_Pin = BUTTON_1;
//	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = BUTTON_2 | BUTTON_3 | BUTTON_4 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
 	
 	// Configure Primary Encoder Pins on TIM2: alternate function, push-pull, 2MHz frequency
// 	GPIO_InitStruct.GPIO_Pin = PRIM_APPS_A_PIN	 | PRIM_APPS_B_PIN	;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);
// 	
// 	GPIO_PinAFConfig(GPIOA, PRIM_APPS_A_PINSOURCE, GPIO_AF_2);
// 	GPIO_PinAFConfig(GPIOA, PRIM_APPS_B_PINSOURCE, GPIO_AF_2);


//    // Configure Hall Effect Pins on TIM16/17 (WHEELS): alternate function, 2MHz, push-pull
////    GPIO_InitStruct.GPIO_Pin =  RIGHT_WHEEL_SPEED_PIN;
////    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
////    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
////    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
////    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
////    GPIO_Init(GPIOA, &GPIO_InitStruct);
//    
////    GPIO_InitStruct.GPIO_Pin =  LEFT_WHEEL_SPEED_PIN;
////    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
////    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
////    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
////    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
////    GPIO_Init(GPIOA, &GPIO_InitStruct);   
//    
////    GPIO_PinAFConfig(GPIOA, RIGHT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM16 pins to AF2
////    GPIO_PinAFConfig(GPIOA, LEFT_WHEEL_PINSOURCE, GPIO_AF_2);					// Connect TIM17 pins to AF2

//    // Configure Brake Input Pin: input mode, push-pull, 2MHz frequency
// 	GPIO_InitStruct.GPIO_Pin = BRAKE_IN_PIN;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
//    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);
// 
//    // Configure ADC Pins: analog input mode, no pull up or pull down
// 	GPIO_InitStruct.GPIO_Pin = STEERING_ANGLE_PIN ;
//    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AN;
//    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL ;
//    GPIO_Init(GPIOA, &GPIO_InitStruct);

//    //Configure GPIO pins for CAN
//    //GPIO_InitStruct.GPIO_Pin = CAN_TX | CAN_RX;
//    //GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;                                        
//    //GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;                            
//    //GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
//    //GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
//    //GPIO_Init(GPIOA, &GPIO_InitStruct);
}






