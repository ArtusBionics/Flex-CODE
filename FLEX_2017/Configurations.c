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

/**
    @brief      Fully contracts fingers, actuates all flexor tendons
    @param      None
    @return     None
*/
void fullFingerContraction (void) {
	//Contract all fingers in GPIOA
	GPIO_SetBits(GPIOA, THUMB_EXT_1);
}

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

	Delay(750);
	
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

}

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
	
	Delay(750);
	
	// turn off
	GPIO_ResetBits(GPIOB, INDEX_FLEX_1);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_2);
	GPIO_ResetBits(GPIOB, INDEX_FLEX_3);
	
	GPIO_ResetBits(GPIOF, THUMB_FLEX_1);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_2);
	GPIO_ResetBits(GPIOA, THUMB_FLEX_3);
	GPIO_ResetBits(GPIOB, THUMB_AD);
}

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

	
	Delay(750);
	
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
}
