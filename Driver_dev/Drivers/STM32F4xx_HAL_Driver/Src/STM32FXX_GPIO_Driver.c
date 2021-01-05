/*
 * STM32FXX_GPIO_Driver.c
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003157
 */

#include "STM32FXX_GPIO_Driver.h"
#include<stdio.h>
void GPIO_PeriClockControl(GPIO_Regdef_t *pGPIOx, uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{GPIOA_PCLK_EN();}

		else if(pGPIOx == GPIOB)
		{GPIOB_PCLK_EN();}

		else if(pGPIOx == GPIOC)
		{GPIOC_PCLK_EN();}

		else if(pGPIOx == GPIOD)
		{GPIOD_PCLK_EN();}

		else if(pGPIOx == GPIOE)
		{GPIOE_PCLK_EN();}

		else if(pGPIOx == GPIOF)
		{GPIOF_PCLK_EN();}

		else if(pGPIOx == GPIOG)
		{GPIOG_PCLK_EN();}

		else if(pGPIOx == GPIOH)
		{GPIOH_PCLK_EN();}

		else
		{GPIOI_PCLK_EN();}
	}
	else
	{
		if(EnorDi == DISABLE)
			{
				if(pGPIOx == GPIOA)
				{GPIOA_PCLK_DI();}

				else if(pGPIOx == GPIOB)
				{GPIOB_PCLK_DI();}

				else if(pGPIOx == GPIOC)
				{GPIOC_PCLK_DI();}

				else if(pGPIOx == GPIOD)
				{GPIOD_PCLK_DI();}

				else if(pGPIOx == GPIOE)
				{GPIOE_PCLK_DI();}

				else if(pGPIOx == GPIOF)
				{GPIOF_PCLK_DI();}

				else if(pGPIOx == GPIOG)
				{GPIOG_PCLK_DI();}

				else if(pGPIOx == GPIOH)
				{GPIOH_PCLK_DI();}

				else
				{GPIOI_PCLK_DI();}
			}
	}
}

void GPIO_Init(GPIO_HANDLE_t *pGPIOHandle)
{
	GPIO_PIN_CONFIG_t *a;
	if(a->GPIO_PinMode <= GPIO_PIN_MODE_Analog)//configure mode
	{uint32_t temp=0;

	temp = pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinMode << (2*pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber);
	pGPIOHandle -> pGPIOx -> MODER |= temp;
	}
	//configure speed
	uint32_t temp1=0;

		temp1 = pGPIOHandle -> GPIO_PIN_CONFIG.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OSPEEDR|=temp1;

	//configure PU PD
	uint32_t temp2=0;

		temp2 = pGPIOHandle ->GPIO_PIN_CONFIG.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->PUPDR|=temp2;

	//configure output type
	uint32_t temp3=0;

		temp3 = pGPIOHandle ->GPIO_PIN_CONFIG.GPIO_PinOPType << (2*pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OTYPER|=temp3;

	if(pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinMode==GPIO_PIN_MODE_AFM)
	{uint32_t temp4,temp5;

		temp4=pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber/8;
		temp5=pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinNumber%8;
		pGPIOHandle->pGPIOx->AFR[temp4]|=pGPIOHandle->GPIO_PIN_CONFIG.GPIO_PinAltFunMode<<(4*temp5);
	}
}
void GPIO_DeInit(GPIO_Regdef_t *pGPIOx)
{


					if(pGPIOx == GPIOA)
					{GPIOA_PCLK_DI();}

					else if(pGPIOx == GPIOB)
					{GPIOB_PCLK_DI();}

					else if(pGPIOx == GPIOC)
					{GPIOC_PCLK_DI();}

					else if(pGPIOx == GPIOD)
					{GPIOD_PCLK_DI();}

					else if(pGPIOx == GPIOE)
					{GPIOE_PCLK_DI();}

					else if(pGPIOx == GPIOF)
					{GPIOF_PCLK_DI();}

					else if(pGPIOx == GPIOG)
					{GPIOG_PCLK_DI();}

					else if(pGPIOx == GPIOH)
					{GPIOH_PCLK_DI();}

					else
					{GPIOI_PCLK_DI();}

}

uint8_t GPIO_ReadFromInputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t Value;
	Value=(pGPIOx->IDR>>PinNumber)*(0x00000001);
	return Value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_Regdef_t *pGPIOx)
{
	uint16_t value1;
	value1=(uint16_t)(pGPIOx->IDR);
	return value1;
}
void GPIO_WriteToOutputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber,uint8_t Value)
{
	if(Value==GPIO_PIN_SET)
	{
		pGPIOx->ODR|=(1<<PinNumber);
	}
	else
	{
		pGPIOx->ODR&=~(1<<PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_Regdef_t *pGPIOx,uint16_t Value)
{
	pGPIOx->ODR=Value;
}
void GPIO_ToggleOutputPin(GPIO_Regdef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR=pGPIOx->ODR^(1<<PinNumber);
}

//void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnorDi);
//void GPIO_IRQHandling(uint8_t PinNumber);
