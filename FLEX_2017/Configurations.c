/**
    @file       Configurations.c
    @brief      Function library for GPIO pin initialisation
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h" 
#include "GPIO.h"
#include "Configurations.h"
#include "SysTick.h"


//Variables
volatile uint16_t delayTime = 750;								// Shuts off current driver after actuation
volatile uint16_t coolOffTime = 4000;							// Delays function moving on to the next so wires can cool off

/**
    @brief      Fully contracts fingers, actuates all flexor tendons
    @param      None
    @return     None
*/

void Fist(void){
	// actuate all flexors
	GPIO_SetBits(GPIOF, THUMB_FLEX_1);
	GPIO_SetBits(GPIOA, THUMB_FLEX_2);
	GPIO_SetBits(GPIOA, THUMB_FLEX_3);
	
	GPIO_SetBits(GPIOB, INDEX_FLEX_1);
	GPIO_SetBits(GPIOB, INDEX_FLEX_2);
	GPIO_SetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_SetBits(GPIOC, MIDDLE_FLEX_1);
	GPIO_SetBits(GPIOC, MIDDLE_FLEX_2);
	GPIO_SetBits(GPIOA, MIDDLE_FLEX_3);
	
	GPIO_SetBits(GPIOA, RING_FLEX);
	
	GPIO_SetBits(GPIOF, PINKY_FLEX);

	Delay(delayTime);
	
	// turn off flexors
	GPIO_ResetBits(GPIOF, THUMB_FLEX_1);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_2);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_3);
	
	GPIO_ResetBits(GPIOB, INDEX_FLEX_1);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_2);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_ResetBits(GPIOC, MIDDLE_FLEX_1);
	GPIO_ResetBits(GPIOC, MIDDLE_FLEX_2);
	GPIO_ResetBits(GPIOA, MIDDLE_FLEX_3);
	
	GPIO_ResetBits(GPIOA, RING_FLEX);
	
	GPIO_ResetBits(GPIOF, PINKY_FLEX);
	
	Delay(coolOffTime);

}

/**
    @brief      Curls thumb and index finger, extends all others
    @param      None
    @return     None
*/

void Artus(void){
	// curl index finger
	GPIO_SetBits(GPIOB, INDEX_FLEX_1);
	GPIO_SetBits(GPIOB, INDEX_FLEX_2);
	GPIO_SetBits(GPIOB, INDEX_FLEX_3);
	
	// curl thumb
	GPIO_SetBits(GPIOF, THUMB_FLEX_1);
	GPIO_SetBits(GPIOA, THUMB_FLEX_2);
	GPIO_SetBits(GPIOA, THUMB_FLEX_3);
	GPIO_SetBits(GPIOB, THUMB_AD);
	
	//Extend other fingers
	GPIO_SetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_SetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_SetBits(GPIOA, MIDDLE_EXT_3);
	
	GPIO_SetBits(GPIOA, RING_EXT);
	
	GPIO_SetBits(GPIOB, PINKY_EXT);
	GPIO_SetBits(GPIOB, PINKY_AB);
	
	Delay(delayTime);
	
	// turn off
	GPIO_ResetBits(GPIOB, INDEX_FLEX_1);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_2);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_ResetBits(GPIOF, THUMB_FLEX_1);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_2);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_3);
	GPIO_ResetBits(GPIOB, THUMB_AD);
	
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_ResetBits(GPIOA, MIDDLE_EXT_3);
	
	GPIO_ResetBits(GPIOA, RING_EXT);
	
	GPIO_ResetBits(GPIOB, PINKY_EXT);
	GPIO_ResetBits(GPIOB, PINKY_AB);
	
	Delay(coolOffTime);
}

/**
    @brief      Extends and abducts all fingers to make a flat "High Five" 
    @param      None
    @return     None
*/

void High_Five(void){
	// set all extensors and abductors
	GPIO_SetBits(GPIOA, THUMB_EXT_1);
	GPIO_SetBits(GPIOA, THUMB_EXT_2);
	GPIO_SetBits(GPIOC, THUMB_EXT_3);
	GPIO_SetBits(GPIOC, THUMB_AB);
	
	GPIO_SetBits(GPIOB, INDEX_AB);
	GPIO_SetBits(GPIOB, INDEX_EXT_1);
	GPIO_SetBits(GPIOB, INDEX_EXT_2);
	GPIO_SetBits(GPIOB, INDEX_EXT_3);
	
	GPIO_SetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_SetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_SetBits(GPIOA, MIDDLE_EXT_3);
	
	GPIO_SetBits(GPIOA, RING_EXT);
	
	GPIO_SetBits(GPIOB, PINKY_EXT);
	GPIO_SetBits(GPIOB, PINKY_AB);

	
	Delay(delayTime);
	
	GPIO_ResetBits(GPIOA, THUMB_EXT_1);
	GPIO_ResetBits(GPIOA, THUMB_EXT_2);
	GPIO_ResetBits(GPIOC, THUMB_EXT_3);
	GPIO_ResetBits(GPIOC, THUMB_AB);
	
	GPIO_ResetBits(GPIOB, INDEX_AB);
	GPIO_ResetBits(GPIOB, INDEX_EXT_1);
	GPIO_ResetBits(GPIOB, INDEX_EXT_2);
	GPIO_ResetBits(GPIOB, INDEX_EXT_3);
	
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_ResetBits(GPIOA, MIDDLE_EXT_3);
	
	GPIO_ResetBits(GPIOA, RING_EXT);
	
	GPIO_ResetBits(GPIOB, PINKY_EXT);
	GPIO_ResetBits(GPIOB, PINKY_AB);
	
	Delay(coolOffTime);
}

/**
    @brief      Pretty self explanatory
    @param      None
    @return     None
*/

void fukOffM8 (void) {
	GPIO_SetBits(GPIOF, THUMB_FLEX_1);
	GPIO_SetBits(GPIOA, THUMB_FLEX_2);
	GPIO_SetBits(GPIOA, THUMB_FLEX_3);
	
	GPIO_SetBits(GPIOB, INDEX_FLEX_1);
	GPIO_SetBits(GPIOB, INDEX_FLEX_2);
	GPIO_SetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_SetBits(GPIOA, RING_FLEX);
	
	GPIO_SetBits(GPIOF, PINKY_FLEX);

	Delay(delayTime);
	
	// turn off flexors
	GPIO_ResetBits(GPIOF, THUMB_FLEX_1);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_2);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_3);
	
	GPIO_ResetBits(GPIOB, INDEX_FLEX_1);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_2);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_ResetBits(GPIOC, MIDDLE_FLEX_1);
	GPIO_ResetBits(GPIOC, MIDDLE_FLEX_2);
	GPIO_ResetBits(GPIOA, MIDDLE_FLEX_3);
	
	GPIO_ResetBits(GPIOA, RING_FLEX);
	
	GPIO_ResetBits(GPIOF, PINKY_FLEX);
	
	//Extend middle finger
	GPIO_SetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_SetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_SetBits(GPIOA, MIDDLE_EXT_3);
	
	Delay(delayTime);
	
	//Turn off middle finger extendors
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_1);
	GPIO_ResetBits(GPIOC, MIDDLE_EXT_2);
	GPIO_ResetBits(GPIOA, MIDDLE_EXT_3);
	
	Delay(coolOffTime);
	
}
