/**
    @file       ISR.c
    @brief      Function library for Various ISRs used in Main function
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h" 
#include "stm32f0xx_it.h"


/**
    @brief      Configures the ISR for P-APPS (Tim2) reading
    @param      None
    @return     Tim2 reading
*/


/**
    @brief      Configures the ISR for S-APPS (Tim3) reading
    @param      None
    @return     Tim3 reading
*/

/**
    @brief  This function handles TIM16 Capture Compare interrupt request.
    @param  None
    @retval None
*/
		
void TIM16_CC_IRQHandler(void)
{ 
	uint16_t IC1ReadValue1 = 0, IC1ReadValue2 = 0;
	uint16_t CaptureNumber = 0;
	uint32_t Capture = 0;
	uint32_t TIM16Freq = 0;
	
  if(TIM_GetITStatus(TIM1, TIM_IT_CC2) == SET) 
  {
    TIM_ClearITPendingBit(TIM1, TIM_IT_CC1);						//Clear TIM1 Capture compare interrupt pending bit
    if(CaptureNumber == 0)
    {
      IC1ReadValue1 = TIM_GetCapture2(TIM1);						//Get the Input Capture value
      CaptureNumber = 1;
    }
    else if(CaptureNumber == 1)
    {
      IC1ReadValue2 = TIM_GetCapture2(TIM1);   			    //Get the Input Capture value 
      if (IC1ReadValue2 > IC1ReadValue1)								//Capture computation
      {
        Capture = (IC1ReadValue2 - IC1ReadValue1); 
      }
      else if (IC1ReadValue2 < IC1ReadValue1)
      {
        Capture = ((0xFFFF - IC1ReadValue1) + IC1ReadValue2); 
      }
      else
      {
        Capture = 0;
      }
      TIM16Freq = (uint32_t) SystemCoreClock / Capture;	// Frequency computation
      CaptureNumber = 0;
    }
  }
}

/**
    @brief  This function handles TIM17 Capture Compare interrupt request.
    @param  None
    @retval None
*/
		
void TIM17_CC_IRQHandler(void)
{ 
	uint16_t IC1ReadValue1 = 0, IC1ReadValue2 = 0;
	uint16_t CaptureNumber = 0;
	uint32_t Capture = 0;
	uint32_t TIM17Freq = 0;
	
  if(TIM_GetITStatus(TIM17, TIM_IT_CC2) == SET) 
  {
    TIM_ClearITPendingBit(TIM17, TIM_IT_CC1);						//Clear TIM1 Capture compare interrupt pending bit
    if(CaptureNumber == 0)
    {
      IC1ReadValue1 = TIM_GetCapture2(TIM17);						//Get the Input Capture value
      CaptureNumber = 1;
    }
    else if(CaptureNumber == 1)
    {
      IC1ReadValue2 = TIM_GetCapture2(TIM17);   			  //Get the Input Capture value 
      if (IC1ReadValue2 > IC1ReadValue1)								//Capture computation
      {
        Capture = (IC1ReadValue2 - IC1ReadValue1); 
      }
      else if (IC1ReadValue2 < IC1ReadValue1)
      {
        Capture = ((0xFFFF - IC1ReadValue1) + IC1ReadValue2); 
      }
      else
      {
        Capture = 0;
      }
      TIM17Freq = (uint32_t) SystemCoreClock / Capture;	// Frequency computation
      CaptureNumber = 0;
    }
  }
}
