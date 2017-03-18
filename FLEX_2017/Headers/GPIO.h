//GPIO.h Header File
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

//Pin assignments for FSM_2017

//Status LEDs (GPIOA)
#define STATUS_R_PIN					GPIO_Pin_8
#define STATUS_G_PIN					GPIO_Pin_9
#define STATUS_B_PIN					GPIO_Pin_10

//Steering Angle Pin (GPIOA)
#define STEERING_ANGLE_PIN				GPIO_Pin_5

//Brake Input Pin (GPIOA)
#define BRAKE_IN_PIN					GPIO_Pin_4

//Wheel Speed Hall Effect Pins (GPIOA)
#define RIGHT_WHEEL_SPEED_PIN			GPIO_Pin_6
#define LEFT_WHEEL_SPEED_PIN			GPIO_Pin_7

//Wheel Speed Hall Effect Pin Source
#define RIGHT_WHEEL_PINSOURCE			GPIO_PinSource6
#define LEFT_WHEEL_PINSOURCE			GPIO_PinSource7

//Primary Encoder Pins (GPIOA)
#define PRIM_APPS_A_PIN					GPIO_Pin_0 
#define PRIM_APPS_B_PIN					GPIO_Pin_1

//Primary Encoder Pin Source
#define PRIM_APPS_A_PINSOURCE           GPIO_PinSource0
#define PRIM_APPS_B_PINSOURCE           GPIO_PinSource1

//Secondary Encoder Pins (GPIOB)
#define SEC_APPS_A_PIN					GPIO_Pin_4
#define SEC_APPS_B_PIN					GPIO_Pin_5

//Secondary Encoder Pin Source
#define SEC_APPS_A_PINSOURCE            GPIO_PinSource4
#define SEC_APPS_B_PINSOURCE            GPIO_PinSource5

//CAN (GPIOA)
#define CAN_TX							GPIO_Pin_12
#define CAN_RX							GPIO_Pin_11

//CAN GPIO Pin Source 
#define CAN_TX_PINSOURCE				GPIO_PinSource12
#define CAN_RX_PINSOURCE 				GPIO_PinSource11

//Constants	

// Function declarations
void ConfigureGPIO(void);


#endif
