/*******************************************************************************
* �ļ���	: SystemState.h
* ����		: Yang
* �汾		: V1.0.0
* ����ʱ��	: 10/16/2014
* ����		: ϵͳ״ָ̬ʾ
*******************************************************************************/
#ifndef SYS_STATE
#define SYS_STATE

#include "Devices.h"

#define NORMAL_STATE
#define OPREATE_ERROR 	 {LED_OFF(LED1 | LED2);LED_ON(LED3);}  //��������LED1 LED2�� �� LED3 ��

#endif
