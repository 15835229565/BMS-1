#include "SysTick.h"

vu32 TimingDelay;

void SysTick_Init()
{
    /* SystemFrequency / 1000    1ms�ж�һ��
     * SystemFrequency / 100000	 10us�ж�һ��
     * SystemFrequency / 1000000 1us�ж�һ��
     */
    if (SysTick_Config(SystemCoreClock / 1000000))
    {
        /* Capture error */
        while (1);
    }
    // �رյδ�ʱ��
    SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;

    NVIC_SetPriority(SysTick_IRQn, 0x0);//SysTick�ж����ȼ�����
}


/*
 * ��������Delay_us
 * ����  ��us��ʱ����,1usΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  :�ⲿ����
 */
void Delay_us(vu32 nTime)
{

    TimingDelay = nTime;

    // ʹ�ܵδ�ʱ��
    SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

    while(TimingDelay != 0);

}

 /*
 * ��������Delay_ms
 * ����  ��ms��ʱ����,1msΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  :�ⲿ����
 */
void Delay_ms(vu32 nTime)
{
    u32 i;

    for(i=0;i<nTime;i++)
    {
        Delay_us(1000);
    }
}

 /*
 * ��������Delay_s
 * ����  ��s��ʱ����,1sΪһ����λ
 * ����  ��- nTime
 * ���  ����
 * ����  :�ⲿ����
 */
void Delay_s(vu32 nTime)
{
    u32 i;

    for(i=0;i<nTime;i++)
    {
        Delay_ms(1000);
    }
}

/*
 * ��������TimingDelay_Decrement
 * ����  ����ȡ���ĳ���
 * ����  ����
 * ���  ����
 * ����  ���� SysTick �жϺ��� SysTick_Handler()����
 */
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}
