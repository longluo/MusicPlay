/************************************************************************************
** File: - E:\ARM\lm3s8962projects\MusicPlay\Source\HAL\IO\Head\io.h
**  
** Copyright (C), Long.Luo, All Rights Reserved!
** 
** Description: 
**      IO.h
** 
** Version: 1.1
** Date created: 20:46:52,14/04/2013
** Author: Long.Luo
** 
** --------------------------- Revision History: --------------------------------
** 	<author>	<data>			<desc>
** 
************************************************************************************/


#ifndef __IO_H__
#define __IO_H__


#ifdef __cplusplus
extern "C"
{
#endif


extern void io_init(void);
extern void io_set_led(tBoolean bOn);
extern void io_set_pwm(tBoolean bOn);
extern void io_pwm_freq(unsigned long ulFreq);
extern void io_pwm_dutycycle(unsigned long ulDutyCycle);


#ifdef __cplusplus
}
#endif

#endif /* __IO_H__ */

