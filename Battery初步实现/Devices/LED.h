#ifndef _LED_H
#define _LED_H

#include "Stm32_Driver.h"

#define LED1 0x01<<0
#define LED2 0x01<<1
#define LED3 0x01<<2
#define LED4 0x01<<3
#define LED5 0x01<<4
#define LED6 0x01<<5
#define LED7 0x01<<6
#define LED8 0x01<<7

/*�ӿں���*/
extern void LED_DriverInit(U8 ledx);//LED�����ʼ��
extern void LED_ON(U8 ledx);        //LED��
extern void LED_OFF(U8 ledx);       //LED��
extern void LED_Change(U8 ledx);    //LED״̬�ı�

#endif

