/*
	Queue.c
	ͨ��ѭ���ж����ݽṹ������������
	BUAA 2008-7-14
	���Գ�

	20110123
	xuechenghao
*/

#include "TypeDef.h"
#include "Queue.h"
#include "Memory.h"


void StartAdd( QueueStruct *Obj)
{
    Obj->Start++;
    if (Obj->Start >= Obj->Length)
    {
        Obj->Start -= Obj->Length;
    }
}

//��ʼ���ж�
void QueueInit( QueueStruct *Obj, U32 Length)
{
    Obj->Start = 0;
    Obj->Count = 0;
    Obj->Length = Length;
    Obj->Data = (U8 *)MemApply(Length * sizeof(U8));
    //TODO:Clear Data
}

//����ж��е�����
void QueueClear( QueueStruct *Obj)
{
    Obj->Start = 0;
    Obj->Count = 0;
}

//�ͷ��ж���ռ�ÿռ�
void QueueFree( QueueStruct *Obj)
{
    Obj->Length = 0;
    free(Obj->Data);
}
//����TRUE��˵��ԭ���ǿն���
bool BytesEnqueue(QueueStruct *q, byte *data, U16 length)	  //������
{
    bool flag = FALSE;
    U16 i;
    if(q->Count == 0)
        flag = TRUE;
    for(i = 0; i < length; i++)
        QueueInsert(q, data[i]);
    return flag;
}
bool ByteDequeue(QueueStruct *q, byte *data)				//������
{
    U8 temp;
    bool result;
    if(QueueFetch(q, &temp) == TRUE)
    {
        *data = temp;
        return TRUE;
    }
    return FALSE;
}
//����ֵ=TRUEʱ˵���ж������²���������Ѽ�ռ���ϵ����ݵ�λ��
U8 QueueInsert( QueueStruct *Obj, U8 c)
{
    U32 t = Obj->Start + Obj->Count;
    if (t >= Obj->Length)
    {
        t -= Obj->Length;
    }
    Obj->Data[t] = c;
    if (Obj->Count == Obj->Length)
    {
        StartAdd(Obj);
        return TRUE;
    }
    else
    {
        Obj->Count++;
        return FALSE;
    }
}

Bool QueueFetch(QueueStruct *Obj, U8 *data)
{
    U8 c;
    if(Obj->Count > 0)
    {
        c = Obj->Data[Obj->Start];
        StartAdd(Obj);
        Obj->Count--;
        *data = c;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

U16 QueueToArray(QueueStruct *Obj, U8 *data)
{
    U16 t = Obj->Count;
    if(Obj->Count == 0)
        return 0;
    if(Obj->Start + Obj->Count < Obj->Length)
        memcpy(data, &Obj->Data[Obj->Start], Obj->Count);
    else
    {
        memcpy(data, &Obj->Data[Obj->Start], Obj->Length - Obj->Start);
        memcpy(&data[Obj->Length - Obj->Start], &Obj->Data[0], Obj->Count - Obj->Length + Obj->Start);
    }
    Obj->Count = 0;
    Obj->Start = 0;
    return t;
}

//������˳���ȡ���ݣ����ָ��λ�������򷵻�0��
U8 QueueRead( QueueStruct *Obj, U32 Num)
{
    U32 t;
    U8 c;
    if (Num < Obj->Count)
    {
        t = Obj->Start + Num;
        //U8 c;
        //cout<<"t="<<t<<endl;
        if (t >= Obj->Length)
        {
            t -= Obj->Length;
        }
        //cout<<"t="<<t<<endl;
        c = Obj->Data[t];
        //cout<<"c="<<(U32)c<<endl;
        return c;
    }
    return 0;
}

U8 FQueueInit(FQueueStruct *Obj)
{
    Obj->Data = (F32 *)MemApply(QUEUE_LENGTH * sizeof(F32));
    Obj->Start =  0;
    return TRUE;
}
//����ֵ=TRUEʱ˵���ж������²���������Ѽ�ռ���ϵ����ݵ�λ��
U8 FQueueInsert(FQueueStruct *Obj, F32 c)
{
    Obj->Start = (Obj->Start + 1) % QUEUE_LENGTH;
    Obj->Data[Obj->Start] = c;
    return TRUE;
}
U8 FQueueDataInit(FQueueStruct *Obj, F32 c)
{
    U8 i;
    for(i = 0; i < QUEUE_LENGTH; i++)
    {
        Obj->Start = (Obj->Start + 1) % QUEUE_LENGTH;
        Obj->Data[Obj->Start] = c;
    }
    return TRUE;
}
U8 FQueueReplace(FQueueStruct *Obj, F32 c, U16 Num)
{
    S16 t;
    t = Obj->Start - Num;
    if(t < 0)
        t = QUEUE_LENGTH + t;
    Obj->Data[t] = c;
}
//������˳���ȡ���ݣ����ָ��λ�������򷵻�0��
F32 FQueueRead(FQueueStruct *Obj, U16 Num)
{
    S16 t;
    t = Obj->Start - Num;
    if(t < 0)
        t = QUEUE_LENGTH + t;
    return Obj->Data[t];
}
U8 LQueueInit(LQueueStruct *Obj)
{
    Obj->Data = (S32 *)MemApply(QUEUE_LENGTH * sizeof(S32));
    Obj->Start =  0;
}
//����ֵ=TRUEʱ˵���ж������²���������Ѽ�ռ���ϵ����ݵ�λ��
U8 LQueueInsert(LQueueStruct *Obj, S32 c)
{
    Obj->Start = (Obj->Start + 1) % QUEUE_LENGTH;
    Obj->Data[Obj->Start] = c;
}
U8 LQueueReplace(LQueueStruct *Obj, S32 c, U16 Num)
{
    S16 t;
    t = Obj->Start - Num;
    if(t < 0)
        t = QUEUE_LENGTH + t;
    Obj->Data[t] = c;
}
//������˳���ȡ���ݣ����ָ��λ�������򷵻�0��
S32 LQueueRead(LQueueStruct *Obj, U16 Num)
{
    S16 t;
    t = Obj->Start - Num;
    if(t < 0)
        t = QUEUE_LENGTH + t;
    return Obj->Data[t];
}
