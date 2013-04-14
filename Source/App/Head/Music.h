/***************************Copyright (c)**************************************
**		
** 			 Copyright(C), Long.Luo, All Rights Reserved! 
**
**				uniqueluolong@gmail.com	
**			
**--------------File Info------------------------------------------------------
** File Name:               Music.h                                         
** Last modified Date:      14-04-2013                                            
** Last Version:            1.1                                                                  
** Description:                                                    
**                                                                                             
**-----------------------------------------------------------------------------
** Created By:              long.luo                                                          
** Created date:            14-04-2013                                                           
** Version:                 1.0                                                                
** Descriptions:            The Music Header File.                                                
**                                                                                                   
******************************************************************************/

#ifndef  __MUSIC_H__
#define  __MUSIC_H__


//  定义低音音名（数值单位：Hz）
#define  L1     262     //  c
#define  L2     294     //  d
#define  L3     330     //  e
#define  L4     349     //  f
#define  L5     392     //  g
#define  L6     440     //  a1
#define  L7     494     //  b1

//  定义中音音名
#define  M1     523     //  c1
#define  M2     587     //  d1
#define  M3     659     //  e1
#define  M4     698     //  f1
#define  M5     784     //  g1
#define  M6     880     //  a2
#define  M7     988     //  b2

//  定义高音音名
#define  H1     1047    //  c2
#define  H2     1175    //  d2
#define  H3     1319    //  e2
#define  H4     1397    //  f2
#define  H5     1568    //  g2
#define  H6     1760    //  a3
#define  H7     1976    //  b3

//  定义时值单位，决定演奏速度（数值单位：ms）
#define  T      3600

//  定义音符结构
typedef struct
{
    short mName;    //  音名：取值L1～L7、M1～M7、H1～H7分别表示低音、中音、高音的
                    //        1234567，取值0表示休止符
    short mTime;    //  时值：取值T、T/2、T/4、T/8、T/16、T/32分别表示全音符、
                    //        二分音符、四分音符、八分音符…，取值0表示演奏结束
}
tNote;


// 定义乐曲：《化蝶》（梁祝）
const tNote HuaDie[] =
{
	{L3, T/4},
    {L5, T/8+T/16},
    {L6, T/16},
    {M1, T/8+T/16},
    {M2, T/16},
    {L6, T/16},
    {M1, T/16},
    {L5, T/8},

    {M5, T/8+T/16},
    {H1, T/16},
    {M6, T/16},
    {M5, T/16},
    {M3, T/16},
    {M5, T/16},
    {M2, T/2},

    {M2, T/8},
    {M2, T/16},
    {M3, T/16},
    {L7, T/8},
    {L6, T/8},
    {L5, T/8+T/16},
    {L6, T/16},
    {M1, T/8},
    {M2, T/8},

    {L3, T/8},
    {M1, T/8},
    {L6, T/16},
    {L5, T/16},
    {L6, T/16},
    {M1, T/16},
    {L5, T/2},

    {M3, T/8+T/16},
    {M5, T/16},
    {L7, T/8},
    {M2, T/8},
    {L6, T/16},
    {M1, T/16},
    {L5, T/8},
    {L5, T/4},

    {L3, T/16},
    {L5, T/16},
    {L3, T/8},
    {L5, T/16},
    {L6, T/16},
    {L7, T/16},
    {M2, T/16},
    {L6, T/4+T/8},
    {L5, T/16},
    {L6, T/16},

    {M1, T/8+T/16},
    {M2, T/16},
    {M5, T/8},
    {M3, T/8},
    {M2, T/8},
    {M3, T/16},
    {M2, T/16},
    {M1, T/8},
    {L6, T/16},
    {L5, T/16},

    {L3, T/4},
    {M1, T/4},
    {L6, T/16},
    {M1, T/16},
    {L6, T/16},
    {L5, T/16},
    {L3, T/16},
    {L5, T/16},
    {L6, T/16},
    {M1, T/16},

    {L5, T/2},
    {0, T/4},
    {0, T/4}, 

    { 0, 0}      //  结束
};


//	 ke xi bu shi ni
const tNote Kexi[] =
{
    {M6, T/4},
	{H5, T/4},
	{H3, T/4},
	{H1, T/4},
	{H2, T/4},

	{M5, T/4},
	{H5, T/4},
	{H3, T/4},
	{M5, T/4},
	{H1, T/4},

	{0, 0},
};


// Little Star
const tNote LittleStar[] =
{
	{M1, T/4},
	{M1, T/4},
	{M5, T/4},
	{M5, T/4},

	{M6, T/4},
	{M6, T/4},
	{M5, T/2},

	{M4, T/4},
	{M4, T/4},
	{M3, T/4},
	{M3, T/4},	

	{M2, T/4},
	{M2, T/4},
	{M1, T/2},

	{0, 0},
};


// Long Long Ago
const tNote LongLongAgo[] =
{
	{M1, T/4},
	{M1, T/8},
	{M2, T/8},
	{M3, T/4},
	{M3, T/8},
	{M4, T/8},
	{M5, T/4},

	{M6, T/8},
	{M5, T/8},
	{M3, T/2+T/4},

	{M5, T/4},
	{M4, T/8},
	{M3, T/8},
	{M2, T/2+T/4},	

	{M4, T/4},
	{M3, T/8},
	{M2, T/8},
	{M1, T/2+T/4},

	{0, 0},
};


#endif /* __MUSIC_H__ */

