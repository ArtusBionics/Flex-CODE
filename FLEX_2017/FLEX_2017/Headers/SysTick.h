/**
    @file       SysTick.h
    @brief      Function library header for the SysTick timer
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#ifndef SYSTICK_H
#define SYSTICK_H

#include "ErrorHandling.h"

static __IO uint32_t TimeDelay;

// Function prototypes
enum ErrorType ConfigureSysTick(void);
void SysTick_Handler(void);
void Delay(__IO uint32_t Time);

#endif
