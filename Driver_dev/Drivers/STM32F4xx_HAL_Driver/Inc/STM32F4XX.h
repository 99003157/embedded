/*
 * STM32F4XX.h
 *
 *  Created on: Dec 28, 2020
 *      Author: 99003157
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include<stdint.h>

/*defining base addresses*/
#define __vo volatile

#define ENABLE 			 1
#define DISABLE 		 0
#define GPIO_PIN_SET   ENABLE
#define GPIO_PIN_RESET DISABLE
//macros for memories
#define FLASHMEM	0x80000000U
#define SRAM2 		0x2001C000U
#define SRAM1 		0x20000000U
#define ROM 		0x1FFF0000U
#define SRAM		SRAM1

//macros for buses
#define AHB1		0x40020000U
#define AHB2		0x50000000U
#define APB1		0x40000000U
#define APB2		0x40010000U
#define PERIPHERAL  APB1

//macros for peripherals in AHB1 bus
#define GPIOA_BASE		0x40020000U
#define GPIOB_BASE		(GPIOA + (0x0400U))
#define GPIOC_BASE		(GPIOB + (0x0400U))
#define GPIOD_BASE		(GPIOC + (0x0400U))
#define GPIOE_BASE		(GPIOD + (0x0400U))
#define GPIOF_BASE		(GPIOE + (0x0400U))
#define GPIOG_BASE		(GPIOF + (0x0400U))
#define GPIOH_BASE		(GPIOG + (0x0400U))
#define GPIOI_BASE		(GPIOH + (0x0400U))
#define RCC_BASE 		(AHB1+(0x3800U))

#define RCC				((RCC_Reg_def_t*)RCC_BASE)
//macros for peripherals in APB bus
#define I2C3		0x40005C00U
#define I2C2		0x40005800U
#define I2C1		0x40005400U

#define UART5		0x40055000U
#define UART4		0x40004C00U

#define USART6      0x40011400U
#define USART3		0x40004800U
#define USART2		0x40004400U
#define USART1      0x40011000U

#define SPI3_I2S3   0x40003C00U
#define SPI2_I2S2   0x40003800U
#define SPI1        0x40013000U

//GPIO peripheral registers
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR [2]; //AFR[1]-(AFRL)Low register, AFR[0]-(AFRH)High Registers

}GPIO_Regdef_t;

typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	uint32_t RESERVED0;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	uint32_t RESERVED1[2];
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	uint32_t RESERVED2;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	uint32_t RESERVED3[2];
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t AHB3LPENR;
	uint32_t RESERVED4;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	uint32_t RESERVED5[2];
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	uint32_t RESERVED6[2];
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t PLLSAICFGR;
	__vo uint32_t DCKCFGR;
}RCC_Reg_def_t;

#define GPIOA (GPIO_Regdef_t*)GPIOA_BASE
#define GPIOB (GPIO_Regdef_t*)GPIOB_BASE
#define GPIOC (GPIO_Regdef_t*)GPIOC_BASE
#define GPIOD (GPIO_Regdef_t*)GPIOD_BASE
#define GPIOE (GPIO_Regdef_t*)GPIOE_BASE
#define GPIOF (GPIO_Regdef_t*)GPIOF_BASE
#define GPIOG (GPIO_Regdef_t*)GPIOG_BASE
#define GPIOH (GPIO_Regdef_t*)GPIOH_BASE
#define GPIOI (GPIO_Regdef_t*)GPIOI_BASE

//clock enable macros
#define GPIOA_PCLK_EN() (RCC -> AHB1ENR |= 1<<0) ;
#define GPIOB_PCLK_EN() (RCC -> AHB1ENR |= 1<<1) ;
#define GPIOC_PCLK_EN() (RCC -> AHB1ENR |= 1<<2) ;
#define GPIOD_PCLK_EN() (RCC -> AHB1ENR |= 1<<3) ;
#define GPIOE_PCLK_EN() (RCC -> AHB1ENR |= 1<<4) ;
#define GPIOF_PCLK_EN() (RCC -> AHB1ENR |= 1<<5) ;
#define GPIOG_PCLK_EN() (RCC -> AHB1ENR |= 1<<6) ;
#define GPIOH_PCLK_EN() (RCC -> AHB1ENR |= 1<<7) ;
#define GPIOI_PCLK_EN() (RCC -> AHB1ENR |= 1<<8) ;

//clock disable macros

#define GPIOA_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0) ;
#define GPIOB_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0) ;
#define GPIOC_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0) ;
#define GPIOD_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0) ;
#define GPIOE_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0) ;
#define GPIOF_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0) ;
#define GPIOG_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0) ;
#define GPIOH_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0) ;
#define GPIOI_PCLK_DI() do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0) ;

#endif /* INC_STM32F4XX_H_ */
