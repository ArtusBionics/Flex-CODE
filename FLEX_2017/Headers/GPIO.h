//GPIO.h Header File
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

//Pin assignments for FLEX_2017

//Status LEDs (GPIOC)
#define STATUS_R_PIN					GPIO_Pin_15
#define STATUS_G_PIN					GPIO_Pin_13
#define STATUS_B_PIN					GPIO_Pin_14

//Fans (GPIOC)
#define FAN_1									GPIO_Pin_0
#define FAN_2									GPIO_Pin_1

//THUMB -- 1 (GPIOF)
#define THUMB_FLEX_1					GPIO_Pin_5

//THUMB -- 1 (GPIOA)
#define THUMB_EXT_1						GPIO_Pin_4
#define THUMB_FLEX_2					GPIO_Pin_5
#define THUMB_EXT_2						GPIO_Pin_6
#define THUMB_FLEX_3					GPIO_Pin_7

// THUMB -- 1 (GPIOC)
#define THUMB_EXT_3						GPIO_Pin_4
#define THUMB_AB							GPIO_Pin_5

//THUMB -- 1 (GPIOB)
#define THUMB_AD							GPIO_Pin_0

//INDEX -- 2 (GPIOB)
#define INDEX_FLEX_1 					GPIO_Pin_1
#define INDEX_EXT_1						GPIO_Pin_2
#define INDEX_FLEX_2					GPIO_Pin_10
#define INDEX_EXT_2						GPIO_Pin_11
#define INDEX_FLEX_3					GPIO_Pin_12
#define INDEX_EXT_3						GPIO_Pin_13
#define INDEX_AB							GPIO_Pin_14
#define INDEX_AD							GPIO_Pin_15

//MIDDLE -- 3 (GPIOC)
#define MIDDLE_FLEX_1					GPIO_Pin_6
#define MIDDLE_EXT_1					GPIO_Pin_7
#define MIDDLE_FLEX_2					GPIO_Pin_8
#define MIDDLE_EXT_2					GPIO_Pin_9

//MIDDLE -- 3	(GPIOA)
#define MIDDLE_FLEX_3					GPIO_Pin_8
#define MIDDLE_EXT_3					GPIO_Pin_9

//RING -- 4 (GPIOA)
//#define RING_FLEX_1					GPIO_Pin_10
//#define RING_EXT_1					GPIO_Pin_11
//#define RING_FLEX_2					GPIO_Pin_12
#define RING_FLEX							GPIO_Pin_12
#define RING_EXT							GPIO_Pin_15
/* Short pins together */

//RING -- 4 (GPIOF)
//#define RING_EXT_2					GPIO_Pin_6
//#define RING_FLEX_3					GPIO_Pin_7
//#define RING_EXT_3
#define RING_AB								GPIO_Pin_6
			

//RING -- 4 (GPIOC)
#define RING_AD								GPIO_Pin_10

//PINKY -- 5 (GPIOC)
//#define PINKY_FLEX_1				GPIO_Pin_11
//#define PINKY_EXT_1					GPIO_Pin_12

//PINKY -- 5 (GPIOD)
#define PINKY_FLEX					GPIO_Pin_2

//PINKY -- 5 (GPIOB)
#define PINKY_AD						GPIO_Pin_3
//#define PINKY_FLEX_3			GPIO_Pin_4
//#define PINKY_EXT_3				GPIO_Pin_5
#define PINKY_EXT						GPIO_Pin_6
#define PINKY_AB						GPIO_Pin_7
	
//Battery Monitoring
#define BATTERY_STATUS			GPIO_Pin_3

//Buttons (GPIOC)
#define BUTTON_1						GPIO_Pin_3

//Buttons (GPIOA)
#define BUTTON_2						GPIO_Pin_0
#define BUTTON_3						GPIO_Pin_1
#define BUTTON_4						GPIO_Pin_2



//Constants	

// Function declarations
void ConfigureGPIO(void);


#endif
