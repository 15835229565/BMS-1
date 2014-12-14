/*******************************************************************************
* �ļ���	: GetSensor.c
* ����		: Yang
* �汾		: V1.0.0
* ����ʱ��	: 10/13/2014
* ����		: ��ȡ���������ݣ�����ص�������ѹ���¶ȵȣ�
*******************************************************************************/
#include "GetSensor.h"

U32 Get_Current(void)	//��λmA
{
	U32 data;
	U16 ads;

	ads=ADS8341_GetChannelData(1);

	if(ads>4000)
		return 0;

	data=(ads-600)*(1000/20);

	return data;
}

U16 Get_Votagle(U8 number)
{
	U16 vcout;
	U16 vref;
	U16 Vvcx;
    
	BQ76925_SetVCx(number);
	vref = ADS8341_GetChannelData(2);
	vcout = ADS8341_GetChannelData(4);
	Vvcx=BQ76925_GetVCx(number,vcout,vref);

	return Vvcx;
}

U16 Get_Temp(void)
{	
	U16 temp;

	temp=250; //
	return temp;

}
