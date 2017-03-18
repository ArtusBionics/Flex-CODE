/**
    @file       ADC.c
    @brief      Function library for ADC initialisation
    @author     UBC Formula Electric
    @version    v1.0.00
    @copyright  GNU General Public License v3
*/

#include "stm32f0xx.h" 
#include "ADC.h"

/**
  * @brief  Configures the ADC for steering angle according to assignments in ADC.h
  * @param  None
  * @retval None
  */
void ConfigureADC(void)
{
    ADC_InitTypeDef     ADC_InitStructure;
     
    /* ADC1 Periph clock enable */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
     
    /* ADCs DeInit */  
    ADC_DeInit(ADC1);
   
    /* Initialize ADC structure */
    ADC_StructInit(&ADC_InitStructure);
   
    /* Configure the ADC1 in discrete mode with a resolution equal to 12 bits  */
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_ScanDirection = ADC_ScanDirection_Upward;
    ADC_Init(ADC1, &ADC_InitStructure); 
   
    /* Convert the ADC1 Channel 5 with 13.5 Cycles as sampling time */ 
    ADC_ChannelConfig(ADC1, STEERING_ANGLE_CHANNEL , ADC_SampleTime_13_5Cycles);

    /* ADC Calibration */
    ADC_GetCalibrationFactor(ADC1);
  
    /* Enable the ADC peripheral */
    ADC_Cmd(ADC1, ENABLE);     
  
    /* Wait the ADRDY flag */
    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY)); 
  
    /* ADC1 regular Software Start Conv */ 
    ADC_StartOfConversion(ADC1);
}
