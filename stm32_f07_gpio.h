/*
 * stm32_f07_gpio.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Samsung
 */

#ifndef INC_STM32_F07_GPIO_H_
#define INC_STM32_F07_GPIO_H_

#include "stm32ff.h"

typedef struct
{
	uint8_t GPIO_pinumber;
	uint8_t GPIO_pinMode;
	uint8_t GPIO_Pinspeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPtype;
	uint8_t GPIO_PinAltfunMode;
}GPIO_pin_config;

typedef struct
{
	GPIO_Regdef_t *ptr_gp_reg;
	GPIO_pin_config pin_config_gpio;
}GPIO_handle;

#define GPIO_PIN_NO0  0
#define GPIO_PIN_NO1  1
#define GPIO_PIN_NO2  2
#define GPIO_PIN_NO3  3
#define GPIO_PIN_NO4  4
#define GPIO_PIN_NO5  5
#define GPIO_PIN_NO6  6
#define GPIO_PIN_NO7  7
#define GPIO_PIN_NO8  8
#define GPIO_PIN_NO9  9
#define GPIO_PIN_NO10 10
#define GPIO_PIN_NO11 11
#define GPIO_PIN_NO12 12
#define GPIO_PIN_NO13 13
#define GPIO_PIN_NO14 14
#define GPIO_PIN_NO15 15

#define GPIO_MODE_INP 	0
#define GPIO_MODE_GPO 	1
#define GPIO_MODE_AFM 	2
#define GPIO_MODE_AM 	3

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_HIGH			2
#define GPIO_SPEED_VERY_HIGH	3

#define GPIO_NO_PULL_PUSH		0
#define GPIO_PULL_UP			1
#define GPIO_PULL_DOWN			2

#define GPIO_OP_TYPE_PP 		0
#define GPIO_OP_TYPE_PD			1

void GPIO_init(GPIO_handle *ptrx);
void GPIO_de_init(GPIO_Regdef_t *ptrx);
void GPIO_peri_clock(GPIO_Regdef_t *ptrx,uint8_t Enordi);
uint16_t GPIO_read_inp_port(GPIO_Regdef_t *ptrx);
uint8_t GPIO_read_inp_pin(GPIO_Regdef_t *ptrx,uint8_t pin_number);
void GPIO_write_op_port(GPIO_Regdef_t *ptrx,uint8_t value);
void GPIO_write_op_pin(GPIO_Regdef_t *ptrx,uint8_t pin,uint8_t value);
void GPIO_toggleoutput_pin(GPIO_Regdef_t *ptrx ,uint8_t pin_no);

#endif /* INC_STM32_F07_GPIO_H_ */
