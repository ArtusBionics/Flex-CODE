/**
    @file       Main.c
    @brief      Main source code for FSM_2017
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

// Header Libraries
#include "stm32f0xx.h"                  // Device header
#include "GPIO.h"
#include "SysTick.h"
#include "ADC.h"
#include "Timers.h" 
#include "Interrupt.h"

// Constants

// Variables

volatile uint16_t ADC1ConvertedValue;
volatile uint32_t TIM16_Wheel_Speed;
//volatile uint8_t Brake_Status;
volatile uint8_t Temporary_Val;

volatile uint8_t Button_1_Status;
volatile uint8_t Button_2_Status;
volatile uint8_t Button_3_Status;
volatile uint8_t Button_4_Status;

volatile uint16_t IC3ReadValuesss1 = 0, IC3ReadValuesss2 = 0;

volatile uint16_t IC3ReadValue1 = 0, IC3ReadValue2 = 0;
volatile uint16_t CaptureNumber = 0;
volatile uint32_t Capture = 0;
volatile uint32_t TIM1Freq = 0;

volatile uint16_t counts = 0;

volatile uint16_t APPS_Position_1 = 0;
volatile uint16_t APPS_Position_2 = 0;

// Structures
EXTI_InitTypeDef   EXTI_InitStructure;
GPIO_InitTypeDef   GPIO_InitStructure;
NVIC_InitTypeDef   NVIC_InitStructure;

// Function Prototypes
void ConfigureEXTI17(void);
static void TIM_Config(void);
void TIM1_CC_IRQHandler(void);
void Test_RGBLED(void);
void Test_ADC(void);
void Test_BrakeSwitch(void);
void Test_Primary_Encoder(void);
void Test_Buttons(void);

/**
* @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
	ConfigureGPIO();
	ConfigureSysTick();
	ConfigureADC();
  ConfigureTIM();
    //ConfigureInterrupt();
    //ConfigureEXTI17();
    //TIM_Config();
    
    // Test Code: Uncomment only one function to test that particular part
    //Test_RGBLED();
    //Test_ADC();
    //Test_BrakeSwitch(); // Changed to Test_Buttons
    //Test_Primary_Encoder(); //Not for us
    
    // Reset encoder counter registers
	
	while(1) {
        APPS_Position_1 = TIM_GetCounter(TIM2);
       // transmit_message(0x322, 0x0, 0x02, (uint64_t) APPS_Position_1);
        Delay(10);
	}	
}

/**
  * @brief  Configure the TIM1 Pins.
  * @param  None
  * @retval None
  */
static void TIM_Config(void)
{
  TIM_ICInitTypeDef  TIM_ICInitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* TIM17 clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM17, ENABLE);

  /* GPIOA clock enable */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  
  /* TIM1 channel 2 pin (PE.11) configuration */
//  GPIO_InitStructure.GPIO_Pin =  LEFT_WHEEL_SPEED_PIN;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Connect TIM pins to AF2 */
//  GPIO_PinAFConfig(GPIOA, LEFT_WHEEL_PINSOURCE, GPIO_AF_2);
  
  /* TIM17 configuration: Input Capture mode ---------------------
     The external signal is connected to TIM17 CH1 pin (PA.07)  
     The Rising edge is used as active edge,
     The TIM17 CCR1 is used to compute the frequency value 
  ------------------------------------------------------------ */

  TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_ICInit(TIM17, &TIM_ICInitStructure);
  
  /* TIM enable counter */
  TIM_Cmd(TIM17, ENABLE);

  /* Enable the CC2 Interrupt Request */
  TIM_ITConfig(TIM17, TIM_IT_CC1, ENABLE);
  
  /* Enable the TIM1 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM17_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
}

void ConfigureEXTI17(void) 
{
    /* Enable GPIOA clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  /* Configure PA0 pin as input floating */
//	GPIO_InitStructure.GPIO_Pin = LEFT_WHEEL_SPEED_PIN;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
  /* Connect EXTI7 Line to PA7 pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource7);

  /* Configure EXTI7 line */
  EXTI_InitStructure.EXTI_Line = EXTI_Line7;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set EXTI7 Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  This function handles External lines 4 to 15 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI4_15_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTI_Line7) != RESET)
  {
        if(counts > 0 && counts < 21845) 
        {
            // Turn on red LED
            GPIO_ResetBits(GPIOA, STATUS_R_PIN);
            
            // Keep green and blue off
            GPIO_SetBits(GPIOA, STATUS_G_PIN);
            GPIO_SetBits(GPIOA, STATUS_B_PIN);
        }
        else if( counts >= 21845 && counts < 43690) 
        {
            // Turn on green LED
            GPIO_ResetBits(GPIOA, STATUS_G_PIN);
            
            // Keep red and blue off
            GPIO_SetBits(GPIOA, STATUS_R_PIN);
            GPIO_SetBits(GPIOA, STATUS_B_PIN);        
        }
        else 
        {
            GPIO_ResetBits(GPIOA, STATUS_B_PIN);
            
            // Keep red and blue off
            GPIO_SetBits(GPIOA, STATUS_R_PIN);
            GPIO_SetBits(GPIOA, STATUS_G_PIN);         
        }
        counts++; 
    
    /* Clear the EXTI line 7 pending bit */
    EXTI_ClearITPendingBit(EXTI_Line7);
  }

}


void TIM17_IRQHandler(void) {
    if(TIM_GetITStatus(TIM17, TIM_IT_CC1) == SET) 
  {
    /* Clear TIM1 Capture compare interrupt pending bit */
    TIM_ClearITPendingBit(TIM17, TIM_IT_CC1);
    if(CaptureNumber == 0)
    {
      /* Get the Input Capture value */
      IC3ReadValue1 = TIM_GetCapture1(TIM17);
      CaptureNumber = 1;
    }
    else if(CaptureNumber == 1)
    {
      /* Get the Input Capture value */
      IC3ReadValue2 = TIM_GetCapture1(TIM17); 
      
      /* Capture computation */
      if (IC3ReadValue2 > IC3ReadValue1)
      {
        Capture = (IC3ReadValue2 - IC3ReadValue1); 
      }
      else if (IC3ReadValue2 < IC3ReadValue1)
      {
        Capture = ((0xFFFF - IC3ReadValue1) + IC3ReadValue2); 
      }
      else
      {
        Capture = 0;
      }
      /* Frequency computation */ 
      TIM1Freq = (uint32_t) SystemCoreClock / Capture;
      CaptureNumber = 0;
    }
  }
    
    /*if(TIM_GetITStatus(TIM17, TIM_IT_CC1) == SET) 
  {
    // Clear TIM1 Capture compare interrupt pending bit 
    TIM_ClearITPendingBit(TIM17, TIM_IT_CC1);
    if(CaptureNumber == 0)
    {
      // Get the Input Capture value 
      IC3ReadValue1 = TIM_GetCapture1(TIM17);
      CaptureNumber = 1;
    }
    else if(CaptureNumber == 1)
    {
       //Get the Input Capture value 
      IC3ReadValue2 = TIM_GetCapture1(TIM17); 
      
      // Capture computation 
      if (IC3ReadValue2 > IC3ReadValue1)
      {
        Capture = (IC3ReadValue2 - IC3ReadValue1); 
      }
      else if (IC3ReadValue2 < IC3ReadValue1)
      {
        Capture = ((0xFFFF - IC3ReadValue1) + IC3ReadValue2); 
      }
      else
      {
        Capture = 0;
      }
      // Frequency computation 
      TIM1Freq = (uint32_t) SystemCoreClock / Capture;
      CaptureNumber = 0;
    }
  }*/
}

/**
    @brief      Tests RGB LED by flashing red, green, and blue every second
    @param      None
    @return     None
*/
void Test_RGBLED(void)
{
    while(1)
    {
        // Turn on red LED
        GPIO_ResetBits(GPIOA, STATUS_R_PIN);
        // Keep green and blue off
        GPIO_SetBits(GPIOA, STATUS_G_PIN);
        GPIO_SetBits(GPIOA, STATUS_B_PIN);
        Delay(1000);
        
        // Turn on green LED
        GPIO_ResetBits(GPIOA, STATUS_G_PIN);     
        // Keep red and blue off
        GPIO_SetBits(GPIOA, STATUS_R_PIN);
        GPIO_SetBits(GPIOA, STATUS_B_PIN);
        Delay(1000);
        
        // Turn on blue LED
        GPIO_ResetBits(GPIOA, STATUS_B_PIN);
        // Keep green and red off
        GPIO_SetBits(GPIOA, STATUS_R_PIN);
        GPIO_SetBits(GPIOA, STATUS_G_PIN);
        Delay(1000);
    }
}

/**
    @brief      Tests ADC by changing the LED colour based on ADC readings
    @note       ADC is configured in DISCRETE mode
    @param      None
    @return     None
*/
void Test_ADC(void)
{
    while(1) 
    {
        /* ADC1 regular Software Start Conv */ 
        ADC_StartOfConversion(ADC1);
        
        /* Get ADC1 converted data */
        ADC1ConvertedValue = ADC_GetConversionValue(ADC1);
  	
    	if(ADC1ConvertedValue > 0 && ADC1ConvertedValue <= 1000)    
        {
            // Turn on red LED
          	GPIO_ResetBits(GPIOA, STATUS_R_PIN);
 		
           	// Keep green and blue off
           	GPIO_SetBits(GPIOA, STATUS_G_PIN);
           	GPIO_SetBits(GPIOA, STATUS_B_PIN);
       	}
        else if(ADC1ConvertedValue > 1000 && ADC1ConvertedValue <= 2000) 
       	{
         	// Turn on green LED
           	GPIO_ResetBits(GPIOA, STATUS_G_PIN);
         
           	// Keep red and blue off
           	GPIO_SetBits(GPIOA, STATUS_R_PIN);
           	GPIO_SetBits(GPIOA, STATUS_B_PIN); 
       	}
        else
       	{
           	// Turn on blue LED
           	GPIO_ResetBits(GPIOA, STATUS_B_PIN);
	
           	// Keep green and red off
          	GPIO_SetBits(GPIOA, STATUS_R_PIN);
           	GPIO_SetBits(GPIOA, STATUS_G_PIN);
       	}
    }
}
/**
    @brief      Tests each push button for hand configuration
    @note       Button 1 					Red LED
								Button 2					Blue LED
								Button 3					Green LED
    @param      None
    @return     None
*/
void Test_Buttons(void) {
	while(1)
	{
		Button_1_Status = GPIO_ReadInputDataBit(GPIOC, BUTTON_1);
		Button_2_Status = GPIO_ReadInputDataBit(GPIOA, BUTTON_2);
	  Button_3_Status = GPIO_ReadInputDataBit(GPIOA, BUTTON_3);
		Button_4_Status = GPIO_ReadInputDataBit(GPIOA, BUTTON_4);
		
		if (Button_1_Status + Button_2_Status + Button_3_Status + Button_4_Status != 1) {
			//Turn off all LEDs
			GPIO_ResetBits(GPIOC, STATUS_B_PIN);
			GPIO_ResetBits(GPIOC, STATUS_R_PIN);
			GPIO_ResetBits(GPIOC, STATUS_G_PIN);
			
		}
		else if (Button_1_Status) {
			//Turn on Red LED
			GPIO_SetBits(GPIOC, STATUS_R_PIN);
			// set all flexors for a curl
			// GPIO_SetBits(GPIOA, THUMB_FLEX_1);
			// GPIO....
			// 
		}
		else if (Button_2_Status) {
			//Turn on Blue LED
			GPIO_SetBits(GPIOC, STATUS_B_PIN);
			// set 
		}
		else if (Button_3_Status) {
			//Turn on Green LED
			GPIO_SetBits(GPIOC, STATUS_G_PIN);
		}
		else if (Button_4_Status) {
			//Turn on all LEDs
			GPIO_SetBits(GPIOC, STATUS_R_PIN);
			GPIO_SetBits(GPIOC, STATUS_G_PIN);
			GPIO_SetBits(GPIOC, STATUS_B_PIN);
		}
		else {
			GPIO_ResetBits(GPIOC, STATUS_B_PIN);
			GPIO_ResetBits(GPIOC, STATUS_R_PIN);
			GPIO_ResetBits(GPIOC, STATUS_G_PIN);
		}
	}
}



