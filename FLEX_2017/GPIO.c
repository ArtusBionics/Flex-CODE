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
	
	// Initialize Fans to be OFF
	GPIO_WriteBit(GPIOC, FAN_1, Bit_SET);
	GPIO_WriteBit(GPIOC, FAN_1, Bit_SET);
	
	// Configure Thumb: output mode, push-pull, 2MHz frequency 
	//GPIOF Ports
	GPIO_InitStruct.GPIO_Pin = THUMB_FLEX_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	//Initialize Thumb GPIOF to be OFF
	GPIO_WriteBit(GPIOF, THUMB_FLEX_1, Bit_RESET);
	//GPIOA Ports
	GPIO_InitStruct.GPIO_Pin = THUMB_EXT_1 | THUMB_FLEX_2 | THUMB_EXT_2 | THUMB_FLEX_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//Initialize Thumb GPIOA to be OFF
	GPIO_WriteBit(GPIOA, THUMB_EXT_1, Bit_RESET);
	GPIO_WriteBit(GPIOA, THUMB_FLEX_2, Bit_RESET);
	GPIO_WriteBit(GPIOA, THUMB_EXT_2, Bit_RESET);
	GPIO_WriteBit(GPIOA, THUMB_FLEX_3, Bit_RESET);
	//GPIOC PORTS
	GPIO_InitStruct.GPIO_Pin = THUMB_EXT_3 | THUMB_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//Initialize Thumb GPIOC to be OFF
	GPIO_WriteBit(GPIOC, THUMB_EXT_3, Bit_RESET);
	GPIO_WriteBit(GPIOC, THUMB_AB, Bit_RESET);
	//GPIOB PORTS
	GPIO_InitStruct.GPIO_Pin = THUMB_AD;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	//Initialize Thumb to be GPIOB OFF
	GPIO_WriteBit(GPIOB, THUMB_AD, Bit_RESET);
	
	//Configure Index: Output mode, push-pull, 2 MHz frequency
	//GPIOB
	GPIO_InitStruct.GPIO_Pin = INDEX_AB | INDEX_AD | INDEX_EXT_1 | INDEX_EXT_2 | INDEX_EXT_3 | INDEX_FLEX_1 | INDEX_FLEX_2 | INDEX_FLEX_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	//Initialize Index GPIOB to be OFF
	GPIO_WriteBit(GPIOB, INDEX_AB, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_AD, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_EXT_1, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_EXT_2, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_EXT_3, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_FLEX_1, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_FLEX_2, Bit_RESET);
	GPIO_WriteBit(GPIOB, INDEX_FLEX_3, Bit_RESET);




	
	//Configure Middle: Output mode, push-pull, 2MHz frequency
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = MIDDLE_FLEX_1 | MIDDLE_EXT_1 | MIDDLE_FLEX_2 | MIDDLE_EXT_2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//Initialize Middle GPIOC to be OFF
	GPIO_WriteBit(GPIOC, MIDDLE_FLEX_1, Bit_RESET);
	GPIO_WriteBit(GPIOC, MIDDLE_EXT_1, Bit_RESET);
	GPIO_WriteBit(GPIOC, MIDDLE_FLEX_2, Bit_RESET);
	GPIO_WriteBit(GPIOC, MIDDLE_EXT_2, Bit_RESET);
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = MIDDLE_FLEX_3 | MIDDLE_EXT_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//Initialize Middle GPIOA to be OFF
	GPIO_WriteBit(GPIOA, MIDDLE_FLEX_3, Bit_RESET);
	GPIO_WriteBit(GPIOA, MIDDLE_EXT_3, Bit_RESET);


	
	//Configure Ring: Output mode, push-pull, 2MHz frequency
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = RING_FLEX | RING_EXT;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	//Initialize Ring GPIOA to be OFF
	GPIO_WriteBit(GPIOA, RING_FLEX, Bit_RESET);
	GPIO_WriteBit(GPIOA, RING_EXT, Bit_RESET);
	//GPIOF
	GPIO_InitStruct.GPIO_Pin = RING_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	//Initialize Ring GPIOF to be OFF
	GPIO_WriteBit(GPIOF, RING_AB, Bit_RESET);	
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = RING_AD;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//Initialize Ring GPIOC to be OFF
	GPIO_WriteBit(GPIOC, RING_AD, Bit_RESET);

	
	//Configure Pinky: output mode, push-pull, 2MHz frequency
	//GPIOD
	GPIO_InitStruct.GPIO_Pin = PINKY_FLEX;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOD, &GPIO_InitStruct);
	//Intialize Pinky GPIOD to be OFF
	GPIO_WriteBit(GPIOA, PINKY_FLEX, Bit_RESET);
	//GPIOB
	GPIO_InitStruct.GPIO_Pin = PINKY_EXT | PINKY_AD | PINKY_AB;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	//Intialize Pinky GPIOB to be OFF
	GPIO_WriteBit(GPIOB, PINKY_EXT, Bit_RESET);
	GPIO_WriteBit(GPIOB, PINKY_AD, Bit_RESET);
	GPIO_WriteBit(GPIOB, PINKY_AB, Bit_RESET);

	//Configure Battery Status Monitor: Input mode, push-pull, 2MHz frequency
	GPIO_InitStruct.GPIO_Pin = BATTERY_STATUS;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	//Configure Buttons
	//GPIOC
	GPIO_InitStruct.GPIO_Pin = BUTTON_1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	//GPIOA
	GPIO_InitStruct.GPIO_Pin = BUTTON_3 | BUTTON_4 ;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}






