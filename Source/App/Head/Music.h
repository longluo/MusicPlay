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


//  ���������������ֵ��λ��Hz��
#define  L1     262     //  c
#define  L2     294     //  d
#define  L3     330     //  e
#define  L4     349     //  f
#define  L5     392     //  g
#define  L6     440     //  a1
#define  L7     494     //  b1

//  ������������
#define  M1     523     //  c1
#define  M2     587     //  d1
#define  M3     659     //  e1
#define  M4     698     //  f1
#define  M5     784     //  g1
#define  M6     880     //  a2
#define  M7     988     //  b2

//  �����������
#define  H1     1047    //  c2
#define  H2     1175    //  d2
#define  H3     1319    //  e2
#define  H4     1397    //  f2
#define  H5     1568    //  g2
#define  H6     1760    //  a3
#define  H7     1976    //  b3

//  ����ʱֵ��λ�����������ٶȣ���ֵ��λ��ms��
#define  T      3600

//  ���������ṹ
typedef struct
{
    short mName;    //  ������ȡֵL1��L7��M1��M7��H1��H7�ֱ��ʾ������������������
                    //        1234567��ȡֵ0��ʾ��ֹ��
    short mTime;    //  ʱֵ��ȡֵT��T/2��T/4��T/8��T/16��T/32�ֱ��ʾȫ������
                    //        �����������ķ��������˷���������ȡֵ0��ʾ�������
}
tNote;


// ����������������������ף��
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

    { 0, 0}      //  ����
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

