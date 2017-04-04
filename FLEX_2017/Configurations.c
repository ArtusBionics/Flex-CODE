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

/**
    @brief      Fully contracts fingers, actuates all flexor tendons
    @param      None
    @return     None
*/
void fullFingerContraction (void) {
	//Contract all fingers in GPIOA
	GPIO_SetBits(GPIOA, THUMB_EXT_1);

	
}
