#ifndef _LIBAT_H
#define _LIBAT_H

#include "ParamAccess.h"
#include "GetSensor.h"
#include "SystemState.h"
#include "Function.h"

#include "Test.h"

/*﮵�ص�������*/
#define BAT_NUMBER 5

#define POL_TIME  10 //����ʱ��

/*����ģʽ*/
#define WAIT_MODE  0x00  //����״̬
#define CHARGE_MODE 0x01  //���״̬
#define DISCHARGE_MODE 0x02	//�ŵ�״̬

#define NORMAL_RES	1000
#define NORMAL_TEMP 200

#define EDV 3000  //�ŵ���ֹ��ѹ3.000V
#define UDV 4190  //�����ֹ��ѹ4.190V

typedef struct
{
	U32 Current;	 //mA
	U16 TotalVotagle;  //�ܵ�ѹ
	U16 SOC;
	U16 Votagle[BAT_NUMBER]; //�����ѹ
	U16	Temp;		//0.1���϶�	
	U16 Age;		 //ʹ�ô���
	F32 Q;
	F32 Quse;
	F32 Qmax;		//�����������λmah
    
	U16 R;			//���� ��λ 0.01��ŷ

	U32 Low_I;		//Ԥ�� �ŵ���� 
	U32 Low_t;		//Ԥ�� �ŵ�ʱ��
}PackLiBATStruct;

typedef struct
{
	U16 Temp;
	U16 SOC;
	U32 R;
}USE_R_Struct;

extern void LiBAT_Init(void);
extern void LiBAT_I_Integral(U32 time);
extern void LiBAT_Low_V(void); 
extern void LiBAT_Update(void);
extern void LiBAT_ShowQ(void);
extern void LiBAT_Send(void);
extern U16 LiBAT_OCV2SOC(U16 ocv);
extern U16 LiBAT_SOC2OCV(U16 soc);
extern void LiBAT_GetSensor(void);

extern PackLiBATStruct LiBATPack;
extern void LiBAT_Mode(void);
extern U8 LiBAT_EndWork(void);
void LiBAT_UpdateRi(void);
F32 LiBAT_GetQuse(void);

extern void LiBAT_InitRiSheet(void);

extern void LiBAT_PrintR(void);

extern void LiBAT_PrintOCVSOC(void);


#endif
