/*
 * stm32ff.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Samsung
 */

#ifndef INC_STM32FF_H_
#define INC_STM32FF_H_

#include<stdint.h>
#define v volatile
#define FLASH_BASEADDR	0x08000000U
#define SRAM1_BASEADDR	0x20000000U
#define SRAM2_BASEADDR	0x2001C000U

#define APB1_BASEADDR	0x40000000U
#define APB2_BASEADDR	0x40010000U
#define AHB1_BASEADDR	0x40020000U
#define AHB2_BASEADDR	0x50000000U
#define AHB3_BASEADDR	0xA0000000U

#define GPIOA_OFFSET	0x0000U
#define GPIOB_OFFSET	0x0400U
#define GPIOC_OFFSET	0x0800U
#define GPIOD_OFFSET	0x0C00U
#define GPIOE_OFFSET	0x1000U
#define GPIOF_OFFSET	0x1400U
#define GPIOG_OFFSET	0x1800U
#define GPIOH_OFFSET	0x1C00U
#define GPIOI_OFFSET	0x2000U

#define RCC_OFFSET		0x3800U


#define GPIOA_	(AHB1_BASEADDR+0x0000)
#define GPIOB_	(AHB1_BASEADDR+GPIOB_OFFSET)
#define GPIOC_	(AHB1_BASEADDR+GPIOC_OFFSET)
#define GPIOD_	(AHB1_BASEADDR+GPIOD_OFFSET)
#define GPIOE_	(AHB1_BASEADDR+GPIOE_OFFSET)
#define GPIOF_	(AHB1_BASEADDR+GPIOF_OFFSET)
#define GPIOG_	(AHB1_BASEADDR+GPIOG_OFFSET)
#define GPIOH_	(AHB1_BASEADDR+GPIOH_OFFSET)
#define GPIOI_	(AHB1_BASEADDR+GPIOI_OFFSET)

#define RCC_BAS	(AHB1_BASEADDR+RCC_OFFSET)
#define SPI1_	(APB2_BASEADDR+SPI1_OFFSET)
#define SPI2_	(APB1_BASEADDR+SPI2_OFFSET)
#define SPI3_	(APB1_BASEADDR+SPI3_OFFSET)
#define SPI4_	(APB2_BASEADDR+SPI4_OFFSET)
#define SPI5_	(APB2_BASEADDR+SPI5_OFFSET)
#define SPI6_	(APB2_BASEADDR+SPI6_OFFSET)

/*PERIPHERAL*/
typedef struct
{
	v uint32_t MODER;
	v uint32_t OTYPER;
	v uint32_t OSPEEDR;
	v uint32_t PUPDR;
	v uint32_t IDR;
	v uint32_t ODR;
	v uint32_t BSRR;
	v uint32_t LCKR;
	v uint32_t AFR[2];


}GPIO_Regdef_t;

typedef struct
{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t  AHB3RSTR;
	uint32_t RESERVED0;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t RESERVED1;
	uint32_t RESERVED2;
	uint32_t AHB1ENR;
	uint32_t AHB2ENR;
	uint32_t AHB3ENR;
	uint32_t RESERVED3;
	uint32_t APB1ENR;
	uint32_t APB2ENR;
	uint32_t RESERVED4;
	uint32_t RESERVED5;
	uint32_t AHB1LPENR;
	uint32_t AHB2LPENR;
	uint32_t AHB3LPENR;
	uint32_t RESERVED6;
	uint32_t APB1LPENR;
	uint32_t APB2LPENR;
	uint32_t RESERVED7;
	uint32_t RESERVED8;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t RESERVED9;
	uint32_t RESERVED10;
	uint32_t SSCGR;
	uint32_t PLLI2SCFGR;
	uint32_t PLLSAICFGR;
	uint32_t DCKCFGR;


}RCC_def_t;
/*
 * peripheral defination
 */
#define GPIOA	((GPIO_Regdef_t *)GPIOA_)
#define GPIOB 	((GPIO_Regdef_t *)GPIOB_)
#define GPIOC 	((GPIO_Regdef_t *)GPIOC_)
#define GPIOD 	((GPIO_Regdef_t *)GPIOD_)
#define GPIOE 	((GPIO_Regdef_t *)GPIOE_)
#define GPIOF 	((GPIO_Regdef_t *)GPIOF_)
#define GPIOG 	((GPIO_Regdef_t *)GPIOG_)
#define GPIOH 	((GPIO_Regdef_t *)GPIOH_)
#define GPIOI 	((GPIO_Regdef_t *)GPIOI_)
#define GPIOJ 	((GPIO_Regdef_t *)GPIOJ_)
#define GPIOK 	((GPIO_Regdef_t *)GPIOK_)
#define RCC		((RCC_def_t *)RCC_BAS)




/**
 * Enable gpio clock
 */
#define GPIOA_PCLK_EN() (RCC->AHB1ENR|=(1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR|=(1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR|=(1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR|=(1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR|=(1<<4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR|=(1<<5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR|=(1<<6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR|=(1<<7))
#define GPIOI_PCLK_EN() (RCC->AHB1ENR|=(1<<8))
/**
 * Enable spi clock
 */
#define SPI1_PCLK_EN()	(RCC->APB2ENR|=(1<<12))
#define SPI2_PCLK_EN()	(RCC->APB1ENR|=(1<<14))
#define SPI3_PCLK_EN()	(RCC->APB1ENR|=(1<<15))
/**
 * Enable I2C Clock
 */
#define I2C1_PCLK_EN()	(RCC->APB1ENR|=(1<<21))
#define I2C2_PCLK_EN()	(RCC->APB1ENR|=(1<<22))
#define I2C3_PCLK_EN()	(RCC->APB1ENR|=(1<<23))
/**
 * Dissble GPIO clock
 */
#define GPIOA_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DIS()	(RCC->AHB1ENR &= ~(1<<8))
/**
 * disable SPI clock
 */
#define SPI1_PCLK_DIS()		(RCC->APB2ENR|=(1<<12))
#define SPI2_PCLK_DIS()		(RCC->APB1ENR|=(1<<14))
#define SPI3_PCLK_DIS()		(RCC->APB1ENR|=(1<<15))
/**
 * disable i2c clock
 */
#define I2C1_PCLK_DIS()	(RCC->APB1ENR&=~(1<<21))
#define I2C2_PCLK_DIS()	(RCC->APB1ENR&=~(1<<22))
#define I2C3_PCLK_DIS()	(RCC->APB1ENR&=~(1<<23))

#define GPIOA_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<0)); (RCC->AHB1RSTR &=~(1<<0)); }while(0)
#define GPIOB_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<1)); (RCC->AHB1RSTR &=~(1<<1)); }while(0)
#define GPIOC_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<2)); (RCC->AHB1RSTR &=~(1<<2)); }while(0)
#define GPIOD_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<3)); (RCC->AHB1RSTR &=~(1<<3)); }while(0)
#define GPIOE_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<4)); (RCC->AHB1RSTR &=~(1<<4)); }while(0)
#define GPIOF_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<5)); (RCC->AHB1RSTR &=~(1<<5)); }while(0)
#define GPIOG_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<6)); (RCC->AHB1RSTR &=~(1<<6)); }while(0)
#define GPIOH_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<7)); (RCC->AHB1RSTR &=~(1<<7)); }while(0)
#define GPIOI_REG_RESET()	do { (RCC->AHB1RSTR |=(1<<8)); (RCC->AHB1RSTR &=~(1<<8)); }while(0)

#define ENABLE 1
#define DISABLE 0
#define SET 1
#define RESET 0
#define GPIO_SET 1
#define GPIO_RESET 0
#include"stm32_f07_gpio.h"

#endif /* INC_STM32FF_H_ */



