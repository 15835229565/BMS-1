#ifndef _FUNCTION_H
#define _FUNCTION_H

#include "TypeDef.h"
#include "memory.h"
#include "Queue.h"

U16 Filter(U16 *pdata, U16 count);

extern U8 CheckSum(U8 *, U8); //У���
extern void Data_Package(QueueStruct* pQueue,U8* data,U16* data_length);	//���ݴ������
extern void Data_UNPackage(U8* data,U16* data_length);//���ݽ������ ,�����ԭ���ݶ�����ÿ�ν�һ�����ݰ���

#endif

//Just test 

//just test
