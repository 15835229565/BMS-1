#include "CAN1.h"

Bool CAN1_HardwareInit(void)
{
    //    GPIO_InitTypeDef       GPIO_InitStructure;
    //	CAN_InitTypeDef        CAN_InitStructure;
    //	CAN_FilterInitTypeDef  CAN_FilterInitStructure;
    //	NVIC_InitTypeDef NVIC_InitStructure;
    //
    //  	/*����ʱ������*/
    //	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB, ENABLE);
    //	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
    //
    //  	/*IO����*/
    //	GPIO_PinRemapConfig(GPIO_Remap1_CAN1, ENABLE);
    //	/* Configure CAN pin: RX */									               // PB8
    //    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    //    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	             // ��������
    //    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //	GPIO_Init(GPIOB, &GPIO_InitStructure);
    //    /* Configure CAN pin: TX */									               // PB9
    //    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    //    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		         // �����������
    //    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    //	GPIO_Init(GPIOB, &GPIO_InitStructure);
    //
    //	/*CAN�Ĵ�����ʼ��*/
    //	CAN_DeInit(CAN1);
    //	CAN_StructInit(&CAN_InitStructure);
    //	/*CAN��Ԫ��ʼ��*/
    //	CAN_InitStructure.CAN_TTCM=DISABLE;			   //MCR-TTCM  �ر�ʱ�䴥��ͨ��ģʽʹ��
    //    CAN_InitStructure.CAN_ABOM=ENABLE;			   //MCR-ABOM  �Զ����߹���
    //    CAN_InitStructure.CAN_AWUM=ENABLE;			   //MCR-AWUM  ʹ���Զ�����ģʽ
    //    CAN_InitStructure.CAN_NART=DISABLE;			   //MCR-NART  ��ֹ�����Զ��ش�	  DISABLE-�Զ��ش�
    //    CAN_InitStructure.CAN_RFLM=DISABLE;			   //MCR-RFLM  ����FIFO ����ģʽ  DISABLE-���ʱ�±��ĻḲ��ԭ�б���
    //    CAN_InitStructure.CAN_TXFP=DISABLE;			   //MCR-TXFP  ����FIFO���ȼ� DISABLE-���ȼ�ȡ���ڱ��ı�ʾ��
    //    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;  //��������ģʽ
    //    CAN_InitStructure.CAN_SJW=CAN_SJW_2tq;		   //BTR-SJW ����ͬ����Ծ��� 2��ʱ�䵥Ԫ
    //    CAN_InitStructure.CAN_BS1=CAN_BS1_6tq;		   //BTR-TS1 ʱ���1 ռ����6��ʱ�䵥Ԫ
    //    CAN_InitStructure.CAN_BS2=CAN_BS2_3tq;		   //BTR-TS1 ʱ���2 ռ����3��ʱ�䵥Ԫ
    //    CAN_InitStructure.CAN_Prescaler =4;		   ////BTR-BRP �����ʷ�Ƶ��  ������ʱ�䵥Ԫ��ʱ�䳤�� 36/(1+6+3)/4=0.8Mbps
    //	CAN_Init(CAN1, &CAN_InitStructure);
    //
    //	/*CAN��������ʼ��*/
    //	CAN_FilterInitStructure.CAN_FilterNumber=0;						//��������0
    //    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;	//�����ڱ�ʶ������λģʽ
    //	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;	//������λ��Ϊ����32λ��
    //	/* ʹ�ܱ��ı�ʾ�����������ձ�ʾ�������ݽ��бȶԹ��ˣ���չID�������µľ����������ǵĻ��������FIFO0�� */
    //    CAN_FilterInitStructure.CAN_FilterIdHigh= (((u32)0x1314<<3)&0xFFFF0000)>>16;				//Ҫ���˵�ID��λ
    //    CAN_FilterInitStructure.CAN_FilterIdLow= (((u32)0x1314<<3)|CAN_ID_EXT|CAN_RTR_DATA)&0xFFFF; //Ҫ���˵�ID��λ
    //    CAN_FilterInitStructure.CAN_FilterMaskIdHigh= 0xFFFF;			//��������16λÿλ����ƥ��
    //    CAN_FilterInitStructure.CAN_FilterMaskIdLow= 0xFFFF;			//��������16λÿλ����ƥ��
    //	//CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0 ;				//��������������FIFO0
    //	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;			//ʹ�ܹ�����
    //	CAN_FilterInit(&CAN_FilterInitStructure);
    //
    //	/*CANͨ���ж�ʹ��*/
    //		/* Configure one bit for preemption priority */
    //	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    //	 	/*�ж�����*/
    //	NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;	   //CAN1 RX0�ж�
    //    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;		   //��ռ���ȼ�0
    //    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			   //�����ȼ�Ϊ0
    //    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    //    NVIC_Init(&NVIC_InitStructure);
    //
    //	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);
    return TRUE;
}
