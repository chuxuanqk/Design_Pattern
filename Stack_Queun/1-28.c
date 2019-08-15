#include "stdio.h"
#include "stdlib.h"

/*队列先进先出*/
#define QueueSize   100     /*假定预分配的队列空间最多为100个元素*/
typedef int DataType;       /*嘉定队列元素的数据类型为字符*/

typedef struct{
    DataType data[QueueSize];
    int front;  /*头指针*/
    int rear;   /*尾指针*/
}SeqQueue;


/*置队列空*/
void Initial(SeqQueue *Q)
{
    Q->front=Q->rear=0;
}

/*判队列空*/
int IsEmpty(SeqQueue *Q)
{
    return Q->front==Q->rear;
}

int IsFull(SeqQueue *Q)
{
    return Q->rear == Q->front+QueueSize-1;
}

void Push(SeqQueue *Q, DataType x)
{
    if(IsFull(Q)){
        printf("队列上溢");
        exit(1);
    }
    Q->data[Q->rear++]=x;
}


DataType Pop(SeqQueue *Q)
{
    if(IsEmpty(Q)){
        printf("队列为空");
        exit(1);
    }
    return Q->data[Q->front++];
}

DataType Top(SeqQueue *Q)
{
    if(IsEmpty(Q))
    {
        printf("队列为空");  /*下溢，退出运行*/
        exit(1);
    }
    return Q->data[Q->front];
}


int main(void)
{
    SeqQueue s;
    DataType first, sec;
    Initial(&s);
    Push(&s, 10);
    Push(&s, 20);
    first = Top(&s);
    printf("first=%d\n", first);
    Pop(&s);
    sec = Top(&s);
    printf("sec=%d\n", sec);
    Pop(&s);

    return 0;
}

