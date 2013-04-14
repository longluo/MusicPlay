/************************************************************************************
** File: - E:\ARM\lm3s8962projects\MusicPlay\Source\HAL\IO\Src\Io.c
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      IO.c
** 
** Version: 1.0
** Date created: 20:47:27,14/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/

#include "hw_ints.h"
#include "hw_memmap.h"
#include "hw_pwm.h"
#include "hw_types.h"
#include "gpio.h"
#include "pwm.h"
#include "sysctl.h"
#include "io.h"


//	Freq and Duty
unsigned long g_ulFrequency; 
unsigned long g_ulDutyCycle;


//	蜂鸣器外设初始化
void io_init(void) 
{ 
    unsigned long ulPWMClock; 
    
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | 
                   SYSCTL_XTAL_8MHZ | SYSCTL_OSC_MAIN); 
				           
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);  	   
    // Enable GPIO bank F to allow control of the LED. 
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);   
	
	/* Configure push buttons as inputs */
	GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,
                         GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    GPIOPadConfigSet(GPIO_PORTE_BASE,
                     GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3,
                     GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

	GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
	GPIODirModeSet(GPIO_PORTE_BASE, GPIO_PIN_0, GPIO_DIR_MODE_IN);                

    // Configure Port F0 for as an output for the status LED. 
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_0); 

    // Initialize LED to OFF (0) 
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0); 

    // Enable Port G1 for PWM output. 
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG); 
    GPIOPinTypePWM(GPIO_PORTG_BASE,GPIO_PIN_1); 

    // Enable the PWM generator. 
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM); 

    // Configure the PWM generator for count down mode with immediate updates 
    // to the parameters. 
    PWMGenConfigure(PWM_BASE, PWM_GEN_0, 
                    PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC); 

    // Divide the PWM clock by 1. 
	SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    // Get the PWM clock. 
	ulPWMClock = SysCtlClockGet(); 

    // Intialize the PWM frequency and duty cycle. 
    g_ulFrequency = 440; 
    g_ulDutyCycle = 15; 

    // Set the period of PWM1. 
    PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, ulPWMClock / g_ulFrequency); 

    // Set the pulse width of PWM1. 
    PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, 
                     ((ulPWMClock * g_ulDutyCycle)/100) / g_ulFrequency); 

    // Start the timers in generator 0. 
    PWMGenEnable(PWM_BASE, PWM_GEN_0); 

	// Initialize LCD 
	RIT128x96x4Init(1000000);
	RIT128x96x4Clear();
	
	/* Setup and enable SysTick with interrupt (100Hz) */
 	SysTickPeriodSet(SysCtlClockGet() / 100);
	SysTickEnable();
	SysTickIntEnable();
} 


// Set the status LED on or off. 
void io_set_led(tBoolean bOn) 
{ 
    // Turn the LED on or off as requested. 
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, bOn ? GPIO_PIN_0 : 0); 
} 

 
// Turn PWM on/off 
void io_set_pwm(tBoolean bOn) 
{ 
    // Enable or disable the PWM1 output. 
    PWMOutputState(PWM_BASE, PWM_OUT_1_BIT, bOn); 
} 


// Set PWM Frequency 
void io_pwm_freq(unsigned long ulFreq) 
{ 
    unsigned long ulPWMClock; 

    // Get the PWM clock 
	ulPWMClock = SysCtlClockGet();  

    // Set the global frequency 
    g_ulFrequency = ulFreq; 

    // Set the period. 
    PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, ulPWMClock / g_ulFrequency); 

    // Set the pulse width of PWM1 
    PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, 
                     ((ulPWMClock * g_ulDutyCycle)/100) / g_ulFrequency); 

} 


// Set PWM Duty Cycle 
void io_pwm_dutycycle(unsigned long ulDutyCycle) 
{ 
    unsigned long ulPWMClock; 

    // Get the PWM clock 
	ulPWMClock = SysCtlClockGet(); 

    // Set the global duty cycle 
    g_ulDutyCycle = ulDutyCycle; 

    // Set the period. 
    PWMGenPeriodSet(PWM_BASE, PWM_GEN_0, ulPWMClock / g_ulFrequency); 

    // Set the pulse width of PWM1 
    PWMPulseWidthSet(PWM_BASE, PWM_OUT_1, 
                     ((ulPWMClock * g_ulDutyCycle)/100) / g_ulFrequency); 
} 

