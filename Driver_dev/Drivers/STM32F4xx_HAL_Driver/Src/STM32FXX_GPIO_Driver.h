/*
 * STM32FXX_GPIO_Driver.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003157
 */

#ifndef INC_STM32FXX_GPIO_DRIVER_H_
#define INC_STM32FXX_GPIO_DRIVER_H_

#include "STM32F4XX.h"

//GPIO pin config
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PIN_CONFIG_t;

//Handle structure GPIO
typedef struct
{
	GPIO_Regdef_t *pGPIOx;
	GPIO_PIN_CONFIG_t GPIO_PIN_CONFIG;
}GPIO_HANDLE_t;

#define GPIO_PIN_NUM_0 0
#define GPIO_PIN_NUM_1 1
#define GPIO_PIN_NUM_2 2
#define GPIO_PIN_NUM_3 3
#define GPIO_PIN_NUM_4 4
#define GPIO_PIN_NUM_5 5
#define GPIO_PIN_NUM_6 6
#define GPIO_PIN_NUM_7 7
#define GPIO_PIN_NUM_8 8
#define GPIO_PIN_NUM_9 9
#define GPIO_PIN_NUM_10 10
#define GPIO_PIN_NUM_11 11
#define GPIO_PIN_NUM_12 12
#define GPIO_PIN_NUM_13 13
#define GPIO_PIN_NUM_14 14
#define GPIO_PIN_NUM_15 15

#define GPIO_PIN_MODE_Input 	0 //input mode
#define GPIO_PIN_MODE_Output 	1 //output mode
#define GPIO_PIN_MODE_AFM 		2//alternate function mode
#define GPIO_PIN_MODE_Analog 	3 //analog mode
#define GPIO_PIN_MODE_IT_FT 	4
#define GPIO_PIN_MODE_IT_RT 	5
#define GPIO_PIN_MODE_IT_RFT 	6

#define GPIO_PinSpeed_Low 		0// low speed
#define GPIO_PinSpeed_Medium 	1//medium speed
#define GPIO_PinSpeed_High 		2//high speed
#define GPIO_PinSpeed_Very_high 3//very high speed

#define GPIO_PinPuPdControl_No_PUPD 	 0 //no pull up or pull down
#define GPIO_PinPuPdControl_PU 			 1 //pull up
#define GPIO_PinPuPdControl_PD 			 2 //pull down
#define GPIO_PinPuPdControl_RESERVED	 3

#define GPIO_PinOPType_PP 1 //push pull
#define GPIO_PinOPType_OD 2 //open drain

//#define GPIO_PinAltFunMode_AF0 0000

void GPIO_PeriClockControl(GPIO_Regdef_t *pGPIOx, uint8_t EnorDi);

void GPIO_Init(GPIO_HANDLE_t *pGPIOHandle);
void GPIO_DeInit(GPIO_Regdef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_Regdef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_Regdef_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber);

//void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnorDi);
//void GPIO_IRQHandling(uint8_t PinNumber);

#endif /* INC_STM32FXX_GPIO_DRIVER_H_ */
