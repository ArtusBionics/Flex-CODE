/**
    @file       Main.c
    @brief      Main source code for FSM_2017
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/
// Ram and Sean

#include "stm32f0xx.h"                  // Device header

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define BSRR_VAL 0x0C00

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_InitTypeDef        GPIO_InitStructure;

/* Temporary variable for Delay function */
static __IO uint32_t TimingDelay;

/* Function prototypes */
void SysTick_Handler(void);
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);

/* */


/**
* @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{

	
	/* Configure SysTick interrupts to occur every 1msec*/
	SysTick_Config(SystemCoreClock / 1000);
	
	while(1) {
		/* Tests RGB LED */
		
		// Turn on red LED
		GPIO_SetBits(GPIOA, GPIO_Pin_8);
		Delay(1000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_8);
		Delay(1000);
		
		// Turn on green LED
		GPIO_SetBits(GPIOA, GPIO_Pin_9);
		Delay(1000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_9);
		Delay(1000);
		
		// Turn on blue LED
		GPIO_SetBits(GPIOA, GPIO_Pin_10);
		Delay(1000);
		GPIO_ResetBits(GPIOA, GPIO_Pin_10);
		Delay(1000);
	}
}


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}
