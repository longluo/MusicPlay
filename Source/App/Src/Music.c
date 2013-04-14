/*-----------------------------------------------------------------------
// Header:		Copyright (c) L.Luo
// File Name: 	Music.c via LM3S8962 Kit
// Author:		L.Luo
// Date:		10.05,2010,Eveing
//	Version 1.0	
//  V2.0	2010/06/17
//	v2.1	2012/02/27 
------------------------------------------------------------------------*/

#include "main.h" 
#include "music.h"
#include "io.h"

#define KEY				0x15

#define UP              GPIO_PIN_0 /* PE0 */
#define DOWN            GPIO_PIN_1 /* PE1 */
#define LEFT            GPIO_PIN_2 /* PE2 */
#define RIGHT           GPIO_PIN_3 /* PE3 */

volatile unsigned char Buttons;
volatile unsigned char KeyCode;

unsigned char choose = 1;


//  演奏乐曲， 在PWM发声的同时点亮LED灯，反之熄灭
void MusicPlay(const tNote *pNote)
{
    while (1)
    {
		if (pNote->mTime == 0)
		{
			break;
		}
		
		io_pwm_freq(pNote->mName);
		io_set_pwm(1);
		io_set_led(1);
		SysCtlDelay(pNote->mTime * (TheSysClock / 2000));

        io_set_pwm(0);
		io_set_led(0);
        SysCtlDelay(10 * (TheSysClock / 2000));

		pNote++;
    }

	SysCtlDelay(2000 * (TheSysClock / 2000));
}


// 中断子程序，实现读取按钮的功能
void SysTickHandler(void)
{
	Buttons = GPIOPinRead(GPIO_PORTE_BASE, (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3));
	KeyCode = Buttons;
}


void delay(long i)
{
	while(i--);
}


/*********************************************************************************************************
** 函数原形：void play(unsigned char i)
** 功能描述：LED 闪烁
** 参数说明：i 闪烁次数
** 返回值：  0
*********************************************************************************************************/
void Play(unsigned char i)
{
	for(; i>0; i--)
	{
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
		delay(1000000);
		GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
		delay(1000000);
	}
}


/*********************************************************************************************************
** 函数原形：void GPIO_PORT_E_ISR(void)
** 功能描述：首先清除中断标志，再熄灭LED。
** 说明：    用KEIL软件时，在Startup.S中添加该中断函数名
** 参数说明：无
** 返回值：  无
*********************************************************************************************************/	  
void GPIO_PORT_E_ISR(void)
{
    long read=0;

    GPIOPinIntClear(GPIO_PORTE_BASE, KEY); /* 清除中断标志 */
	read = GPIOPinRead(GPIO_PORTE_BASE, 15) & 0x0f;/*读IO口值*/

	while (1)
	{
		  if((GPIOPinRead(GPIO_PORTE_BASE,15)&0x0f)==0x0f)
		  break;
	}

	switch(read)
	{
	    case 0x0e:
			 Play(1);
			 break;

		case 0x0d:	
			 Play(2);
			 break;

		case 0x0b:	
			 Play(3);		   
			 break;

		case 0x07:	
			 Play(4);
			 break;

		default:
			break;
	 }
}


//	Display the Music
void Display()
{
	unsigned char buttons, b;

	buttons = ~Buttons;
	b = Buttons;
		
	RIT128x96x4StringDraw("    Songs List        ", 0, 10*1+6, 11);
	RIT128x96x4StringDraw("  1.Hua Die:          ", 0, 10*2+6, 11);
	RIT128x96x4StringDraw("  2.Kexi:             ", 0, 10*3+6, 11);
	RIT128x96x4StringDraw("  3.Little Star:      ", 0, 10*4+6, 11);
	RIT128x96x4StringDraw("  4.Henjiuyiqian:     ", 0, 10*5+6, 11);

	if ((buttons ^ b) & RIGHT)
	{
		RIT128x96x4StringDraw(" >1.Hua Die:       On ", 0, 10*choose+6, 11);
	}	
}


