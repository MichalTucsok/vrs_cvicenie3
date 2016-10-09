/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 6.0.0   2016-10-09

The MIT License (MIT)
Copyright (c) 2009-2016 Atollic AB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"


/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/* Private functions */
void delay(uint32_t cas)
{
	uint32_t i;
	for(i=0;i<cas;i++)
	{

	}
}

/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/
int main(void)
{
	uint8_t button;
	uint8_t pombutton;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

	GPIO_InitTypeDef gpioInitStruc;

	  gpioInitStruc.GPIO_Mode = GPIO_Mode_OUT;
	  gpioInitStruc.GPIO_OType = GPIO_OType_PP;
	  gpioInitStruc.GPIO_Pin = GPIO_Pin_5;
	  gpioInitStruc.GPIO_Speed = GPIO_Speed_400KHz;
	  gpioInitStruc.GPIO_PuPd = GPIO_PuPd_UP;

	  GPIO_Init(GPIOA, &gpioInitStruc);

	  GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  GPIO_WriteBit(GPIOA, GPIO_Pin_5,1);
      GPIO_WriteBit(GPIOA, GPIO_Pin_5,0);
      GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
      GPIO_ToggleBits(GPIOA, GPIO_Pin_5);

      GPIO_InitTypeDef gpioInitStrucbutton;

       gpioInitStrucbutton.GPIO_Mode = GPIO_Mode_IN;
       gpioInitStrucbutton.GPIO_OType = GPIO_OType_PP;
       gpioInitStrucbutton.GPIO_Pin = GPIO_Pin_13;
       gpioInitStrucbutton.GPIO_PuPd = GPIO_PuPd_NOPULL;

       GPIO_Init(GPIOC, &gpioInitStrucbutton);

  /**
  *  IMPORTANT NOTE!
  *  See the <system_*.c> file and how/if the SystemInit() function updates 
  *  SCB->VTOR register. Sometimes the symbol VECT_TAB_SRAM needs to be defined 
  *  when building the project if code has been located to RAM and interrupts 
  *  are used. Otherwise the interrupt table located in flash will be used.
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /**
  *  At this stage the microcontroller clock setting is already configured,
  *  this is done through SystemInit() function which is called from startup
  *  file (startup_stm32l1xx_hd.s) before to branch to application main.
  *  To reconfigure the default setting of SystemInit() function, refer to
  *  system_stm32l1xx.c file
  */

  /* TODO - Add your application code here */


  /* Infinite loop */
  while (1)
  {
	  button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
	  			if (button==0)
	  			{
	  				GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  			}
	  			else
	  			{
	  				GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  			}

	  /* GPIO_SetBits(GPIOA, GPIO_Pin_5);
	  	  delay(1000000);
	  	  //vypni LED
	  	  GPIO_ResetBits(GPIOA, GPIO_Pin_5);
	  	  delay(1000000); */
  }
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}

/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}
