/*
 * Stm32f07xx_gpio.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Samsung
 */
#include"stm32_f07_gpio.h"
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: None
 */

void GPIO_peri_clock(GPIO_Regdef_t *ptrx,uint8_t Enordi)
{
	if(Enordi == ENABLE)
	{
		if(ptrx==GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if(ptrx==GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		else if(ptrx==GPIOC)
			{
			GPIOC_PCLK_EN();
			}
		else if(ptrx==GPIOD)
				{
			GPIOD_PCLK_EN();
				}
		else if(ptrx==GPIOE)
				{
			GPIOE_PCLK_EN();
				}
		else if(ptrx==GPIOF)
				{
			GPIOF_PCLK_EN();
				}
		else if(ptrx==GPIOG)
				{
			GPIOG_PCLK_EN();
				}
		else if(ptrx==GPIOH)
				{
			GPIOH_PCLK_EN();
				}
		else if(ptrx==GPIOI)
				{
			GPIOI_PCLK_EN();
				}

	}
	else
	{
		if(ptrx==GPIOA)
				{
			GPIOA_PCLK_DIS();
				}
				else if(ptrx==GPIOB)
				{
					GPIOB_PCLK_DIS();
				}
				else if(ptrx==GPIOC)
					{
					GPIOC_PCLK_DIS();
					}
				else if(ptrx==GPIOD)
						{
					GPIOD_PCLK_DIS();
						}
				else if(ptrx==GPIOE)
						{
					GPIOE_PCLK_DIS();
						}
				else if(ptrx==GPIOF)
						{
					GPIOF_PCLK_DIS();
						}
				else if(ptrx==GPIOG)
						{
					GPIOG_PCLK_DIS();
						}
				else if(ptrx==GPIOH)
						{
					GPIOH_PCLK_DIS();
						}
				else if(ptrx==GPIOI)
						{
					GPIOI_PCLK_DIS();
						}
	}
}
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: None
 */

void GPIO_init(GPIO_handle *ptrx)
{

	//1. cONFIG THE MODE
	uint32_t temp=0;
	temp= (ptrx->pin_config_gpio.GPIO_pinMode<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->MODER &=~(0x3<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->MODER|=temp;
	// CONFIG THE SPEED
	temp =(ptrx->pin_config_gpio.GPIO_Pinspeed<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->OSPEEDR &=~(0x3<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->OSPEEDR |=temp;
	// CONDFIG PUSH PULL
	temp=(ptrx->pin_config_gpio.GPIO_pinumber<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->PUPDR &=~(0x3<<(2*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->PUPDR|=temp;
	// CONFIG alternating
	if(ptrx->pin_config_gpio.GPIO_pinMode==GPIO_MODE_AFM )
	{
		uint8_t temp1,temp2;
		temp1=ptrx->pin_config_gpio.GPIO_pinumber;
		temp1=temp1/8;
		temp2=ptrx->pin_config_gpio.GPIO_pinumber;
		temp2=temp2%8;
		ptrx->ptr_gp_reg->AFR[temp1]&=~(0xF <<(4*temp2));
		ptrx->ptr_gp_reg->AFR[temp1]|=(ptrx->pin_config_gpio.GPIO_PinAltfunMode<<(4*temp2));
	}
	//config output
	temp=ptrx->pin_config_gpio.GPIO_PinOPtype<<(1*ptrx->pin_config_gpio.GPIO_pinumber);
	ptrx->ptr_gp_reg->OTYPER&=~(0x1<<(1*ptrx->pin_config_gpio.GPIO_pinumber));
	ptrx->ptr_gp_reg->OTYPER|=temp;
}
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: None
 */

void GPIO_de_init(GPIO_Regdef_t *ptrx)
{
if(ptrx==GPIOA)
{
	 GPIOA_REG_RESET();
}
else if(ptrx==GPIOB)
{
	 GPIOB_REG_RESET();
}
else if(ptrx==GPIOC)
{
	 GPIOC_REG_RESET();
}
else if(ptrx==GPIOD)
{
	 GPIOD_REG_RESET();
}
else if(ptrx==GPIOE)
{
	 GPIOE_REG_RESET();
}
else if(ptrx==GPIOF)
{
	 GPIOF_REG_RESET();
}else if(ptrx==GPIOG)
{
	 GPIOG_REG_RESET();
}
else if(ptrx==GPIOH)
{
	 GPIOH_REG_RESET();
}
else if(ptrx==GPIOI)
{
	 GPIOI_REG_RESET();
}

}

/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: Integer
 */

uint16_t GPIO_read_inp_port(GPIO_Regdef_t *ptrx)
{
uint16_t value;
value=(uint16_t)ptrx->IDR;
return value;
}
uint8_t GPIO_read_inp_pin(GPIO_Regdef_t *ptrx,uint8_t pin_number)
{
uint8_t value;
value=(uint8_t)(ptrx->IDR);
value=value>>(pin_number);
return value;
}
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: Integer
 */

void GPIO_write_op_port(GPIO_Regdef_t *ptrx,uint8_t value)
{
ptrx->ODR=value;

}
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: None
 */

void GPIO_write_op_pin(GPIO_Regdef_t *ptrx,uint8_t pin,uint8_t value)
{
if(value==GPIO_SET)
{
	ptrx->ODR|=(1<<pin);
}
else
{
	ptrx->ODR &=~(1<<pin);
}
}
/*
 *@Brief:
 * @Param1:
 * @Param2:
 * @return Value: None
 */

void GPIO_toggleoutput_pin(GPIO_Regdef_t *ptrx ,uint8_t pin_no)
{
ptrx->ODR ^=(1<<pin_no);
}
