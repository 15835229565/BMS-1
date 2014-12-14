#include "tim3.h"

U32 TIM3_COUNT;
U32 TIM3_INTERRUPT_TIME;

void TIM3_InterruptInit(U32 time)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    /*����1ms ����һ�ζ�ʱ������ж�*/
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
    TIM_DeInit(TIM3);
    TIM_TimeBaseStructure.TIM_Period = 1000 - 1;		/* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
    TIM_TimeBaseStructure.TIM_Prescaler = (72 - 1);	/* ʱ��Ԥ��Ƶ�� 72M/72 */
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; 		/* ������Ƶ */
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; /* ���ϼ���ģʽ */
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

    NVIC_PriorityGroupConfig(Devices_PriorityGroup);
    NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = TIM3_PreemptionPriority;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = TIM3_SubPriority;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);			 /* �������жϱ�־ */
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIM3, ENABLE);							/* ����ʱ�� */

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , DISABLE);		/*�ȹرյȴ�ʹ��*/
	TIM3_COUNT=0;
	TIM3_INTERRUPT_TIME=time;
}


void TIM3_StartTime(void)
{
    TIM3_COUNT=0;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , ENABLE);
    TIM_Cmd(TIM3, ENABLE);
}

void TIM3_StopTime(void)
{
    TIM_Cmd(TIM3, DISABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 , DISABLE);
}

void TIM3_SetTimeCount(U32 count)
{
	TIM3_COUNT=count;
}

U32 TIM3_GetTimCount(void)
{
	return TIM3_COUNT; 
}

void TIM3_TimeCountAdd(void)
{
	TIM3_COUNT++;
}


void TIM3_SetTimeInterruptISR(TimerISRFunc fp)
{
    TIM3_ISR_HANDLER = fp;
}

U32 TIM3_GetInterruptTime(void)
{
	return TIM3_INTERRUPT_TIME;
}
