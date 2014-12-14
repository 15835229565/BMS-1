#include "User.h"
U8 SEND_OCV_SOC;
extern F32 THIS_QUSE;
U8 DISCHATGE_TEST;
U8 PRINT_R;
U8 PRINT_OCV_SOC;

int main(void)
{
	SysDriverInit();

	/*ϵͳ������ʼ��*/
	TIM3_StartTime();//��ʼ��ȡ��������
			
	/*﮵�ز�����ʼ��*/
	LiBAT_Init();
	TIM2_StartTime();//��ʼ���������ݲɼ�
	TIM4_StartTime();//��ز������¼����ͣ���������ʾ

	while(1)
	{
		/*����ģʽ�ж�*/
		LiBAT_Mode();

    	while(1)
    	{
			if(LiBAT_EndWork())
				break;
		}
		
	}   
}

void SysDriverInit(void)
{
    /*MCUӲ����ʼ��*/

	/*�δ�ʱ�Ӷ�ʱ����ʼ��*/
    SysTick_Init();
	Delay_ms(1000);
   
    /*UART���ڳ�ʼ��*/
    UART_DriverInit(CHANNEL1, 115200, 256);

    UART_DriverInit(CHANNEL2,115200,256);
    
    /*��ʱ���жϳ�ʼ��*/
    TIM2_InterruptInit(TIME2_INTERRUPT_TIME);
    TIM2_SetTimeInterruptISR(Timer2_InterruptHandler); //

    TIM3_InterruptInit(TIME3_INTERRUPT_TIME);
    TIM3_SetTimeInterruptISR(Timer3_InterruptHandler); //
   
    TIM4_InterruptInit(TIME4_INTERRUPT_TIME);
    TIM4_SetTimeInterruptISR(Timer4_InterruptHandler); //

    /*Devices��ʼ��*/

    /*LED��ʼ��*/
    LED_DriverInit(LED3 | LED4 | LED5 | LED6 | LED7);
	LED_OFF(LED4 | LED5 | LED6 | LED7);

    /*ADS8341��ʼ��*/
	ADS8341_Init();

	/*BQ76925��ʼ��*/
	BQ76925_Init();
}

void Timer2_InterruptHandler(void)
{
	 LiBAT_GetSensor();	  //���µ����ѹ���������¶�

  	 LiBAT_I_Integral(TIME2_INTERRUPT_TIME);	//�������֣�����Q 
}

void Timer3_InterruptHandler(void)
{
	 UPort1_RxDataHandler();  //�������ݴ���
}

void Timer4_InterruptHandler(void)
{
	 U16 ocv;

     LiBAT_Update();						//﮵��״̬���� V SOC  
	 LiBAT_Send();	 
	 LiBAT_ShowQ();

	 if(PRINT_R)
	 {
	 	LiBAT_PrintR();
		PRINT_R=0;
	 }
	 
	 if(PRINT_OCV_SOC)
	 {
	 	LiBAT_PrintOCVSOC();
		PRINT_OCV_SOC=0;
	}
}


/*����1�������ݴ���*/
void UPort1_RxDataHandler(void)
{
	U8 data[256];
	U16 length;
	U16 charge;

	Data_UNPackage(data,&length);	 //��ȡһ���������

	if(data[0]!=0x01)
		return;

	/*Low_t Low_I Age Qmax OCV_SOC Ri*/
	if(data[1]==0x00)
	{
	/*���Flash*/
     Store_State(0x00);

	}
	else if(data[1]==0x01)
	{
	/*�����������*/
		charge=data[3];
		charge=data[2]  | charge<<8;
		Store_Qmax(charge);

	}
	else if(data[1]==0x02)		
	{
	/*����ʹ�ô���*/
		Store_Age(1);
	}
	else if(data[1]==0x30)
	{
	/*��ȡOCV_SOC���ݱ�*/
		PRINT_OCV_SOC=1;

	 
	}
	else if(data[1]==0x31)
	{
	/*��ȡRi��*/
		PRINT_R=1;
	}
	else if(data[1]==0xF0)
	{
	  /*����ŵ����*/
	  	if(data[2]==0x01)
	  	{
		/*��һ�ηŵ����*/
			DISCHATGE_TEST=1;
		}
		else if(data[2]==0x02)
		{
		/*�ڶ��ηŵ����*/
		}
	}
	else if(data[1]==0xF1)
	{
	   /*�˳��ŵ����*/
	   DISCHATGE_TEST=0;

	}
	else 
	{

	}
}





