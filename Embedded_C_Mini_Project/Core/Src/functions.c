/*
 * operations.c
 *
 *  Created on: Oct 5, 2020
 *      Author: Training
 */
#include <functions.h>
#include "main.h"
/*
 * @Breif Description - Switch On the LED to show the system is On and turn off the LED to indicate
 * @Function - system begin and initialise
 *
 * @Param1- FLAG which is an interuppt raised when the switch is pressed
 *
 * @Retval - None
 *
 * @Deigned By- Rahul L
 *
 * @Date and Time- 05/10/2020
 */
void sysbegin(uint8_t FLAG)
{
	HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, FLAG);
}

/*
 * @Breif Description - Function to initialise, start conversion and return a converted value
 * @Function Reading the ADC
 *
 * @Param1- handle of the adc 1
 *
 *
 * @Retval - Converted digital value
 *
 * @Deigned By- Rahul L
 *
 * @Date and Time- 05/10/2020
 */
uint16_t AdcRead(ADC_HandleTypeDef hadc1)
{
	uint16_t DigitalValue;
	HAL_ADC_Start(&hadc1);
    if(HAL_ADC_PollForConversion(&hadc1, 5)== HAL_OK)
	{
		DigitalValue = HAL_ADC_GetValue(&hadc1);				   //adc value is stored in adcvalue
    }
    return DigitalValue;
}
