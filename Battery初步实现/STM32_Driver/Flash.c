#include "Flash.h"

#define PageSize (0x0001)
//Flash ÿҳ2kb

/*
size :U32 ����
*/

Bool Flash_Write_U32(u32 StartAddr,u32 *p_data,u32 size)
{	
	volatile FLASH_Status FLASHStatus;	
	u32 EndAddr=StartAddr+size*4;	
	vu32 NbrOfPage = 0;	
	u32 EraseCounter = 0x0, Address = 0x0;
	int i;
	int MemoryProgramStatus=1;
	
	FLASH_Unlock();          //
	NbrOfPage=((EndAddr-StartAddr-1)/PageSize)+1;
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASHStatus=FLASH_COMPLETE;
	for(EraseCounter=0;(EraseCounter<NbrOfPage)&&(FLASHStatus==FLASH_COMPLETE);EraseCounter++)
	{		
		FLASHStatus=FLASH_ErasePage(StartAddr+(PageSize*EraseCounter));	
	}
	Address = StartAddr;
	i=0;
	while((Address<EndAddr)&&(FLASHStatus==FLASH_COMPLETE))	
	{	FLASHStatus=FLASH_ProgramWord(Address,p_data[i++]);
		Address=Address+4;

	}
	Address = StartAddr;
	i=0;
	while((Address < EndAddr) && (MemoryProgramStatus != 0))
	{	
		if((*(vu32*) Address) != p_data[i++])
		{		MemoryProgramStatus = 0;
				return 1;
		}
		Address += 4;
	}
	return 0;
}

Bool Flash_Read_U32(u32 StartAddr,u32 *p_data,u32 size)
{
	u32 EndAddr=StartAddr+size*4;
	int MemoryProgramStatus=1;
	u32 Address = 0x0;
	int i=0;
	Address = StartAddr;
	while((Address < EndAddr) && (MemoryProgramStatus != 0))
	{
		p_data[i++]=(*(vu32*) Address);
		Address += 4;	
	}
	return 0;
}

void Flash_Write_F32(U32 StartAddr,F32 *p_data,u32 size)
{
	Flash_Write_U32(StartAddr,(U32*)(p_data),size);
} 

void Flash_Read_F32(U32 StartAddr,F32 *p_data,u32 size)
{
	Flash_Read_U32(StartAddr,(U32*)(p_data),size);	
}

//����STM32��FLASH
void STMFLASH_Unlock(void)
{
//  FLASH->KEYR=FLASH_KEY1;//д���������.
//  FLASH->KEYR=FLASH_KEY2;
}
//flash����
void STMFLASH_Lock(void)
{
  FLASH->CR|=1<<7;//����
}
//�õ�FLASH״̬
u8 STMFLASH_GetStatus(void)
{    
       u32 res;         
       res=FLASH->SR;
       if(res&(1<<0))return 1;            //æ
       else if(res&(1<<2))return 2;  //��̴���
       else if(res&(1<<4))return 3;  //д��������
       return 0;                                     //�������
}
//�ȴ��������
//time:Ҫ��ʱ�ĳ���
//����ֵ:״̬.
u8 STMFLASH_WaitDone(u16 time)
{
       u8 res;
       do
       {
              res=STMFLASH_GetStatus();
              if(res!=1)break;//��æ,����ȴ���,ֱ���˳�.
              Delay_us(1); time--;             
        }while(time);
        if(time==0)res=0xff;//TIMEOUT
        return res;
}
//����ҳ
//paddr:ҳ��ַ
//����ֵ:ִ�����
u8 STMFLASH_ErasePage(u32 paddr)
{
       u8 res=0;
       res=STMFLASH_WaitDone(0X5FFF);//�ȴ��ϴβ�������,>20ms   
       if(res==0)
       {
              FLASH->CR|=1<<1;//ҳ����
              FLASH->AR=paddr;//����ҳ��ַ
              FLASH->CR|=1<<6;//��ʼ����           
              res=STMFLASH_WaitDone(0X5FFF);//�ȴ���������,>20ms 
              if(res!=1)//��æ
              {
                     FLASH->CR&=~(1<<1);//���ҳ������־.
              }
       }
       return res;
}

//��FLASHָ����ַд�����
//faddr:ָ����ַ(�˵�ַ����Ϊ2�ı���!!)
//dat:Ҫд�������
//����ֵ:д������
u8 FLASH_WriteHalfWord(u32 faddr, u16 dat)
{
	FLASH_Unlock();          //
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASH_ErasePage(faddr);			//ÿ�β���1ҳ
	FLASH_ProgramHalfWord(faddr, dat); 
}

//��FLASHָ����ַд�����
//faddr:ָ����ַ(�˵�ַ����Ϊ2�ı���!!)
//dat:Ҫд�������
//����ֵ:д������
u8 FLASH_Write_U16(u32 faddr, u16* pdata,u16 length)
{
	u16 i;
	FLASH_Unlock();          //
	FLASH_ClearFlag(FLASH_FLAG_BSY | FLASH_FLAG_EOP | FLASH_FLAG_PGERR | FLASH_FLAG_WRPRTERR);
	FLASH_ErasePage(faddr);			//ÿ�β���1ҳ
	for(i=0;i<length;i++)
	{
		FLASH_ProgramHalfWord(faddr+2*i,pdata[i]); 
	}
}

//��ȡָ����ַ�İ���(16λ����)
//faddr:����ַ
//����ֵ:��Ӧ����.
u16 FLASH_ReadHalfWord(u32 faddr)
{
       return *(vu16*)faddr;
}

