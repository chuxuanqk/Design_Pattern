#include <stdio.h>
#include <stdlib.h>

/*链队列: 入队，出队*/

#define QueueSize   100   /*假定预分配的队列空间最多为100个元素*/
typedef char DataType;
typedef struct node{
    DataType data;
    struct node *next;
}QueueNode;                  /*队列节点*/

typedef struct{
    QueueNode *front;       /*头指针*/
    QueueNode *rear;        /*尾指针*/
}LinkQueue;


void Initial(LinkQueue *Q){
    Q->front=Q->rear=NULL;
}


int IsEmpty(LinkQueue *Q){
    return (Q->front==NULL&&Q->rear==NULL);
}


void Push(LinkQueue *Q, DataType x){
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));  /*申请新结点*/
    p->data = x;
    p->next = NULL;
    if(IsEmpty(Q))
        Q->front=Q->rear=p;
    else{ /*x插入非空队列的尾*/
        Q->rear->next = p;      /*p链到原队尾结点后*/
        Q->rear = p;            /*队尾指针指向新的尾*/
    }
}

DataType Pop(LinkQueue *Q){
    DataType x;
    QueueNode *p;
    if(IsEmpty(Q)){
        printf("队列为空");
        exit(1);
    }
    p = Q->front;               /*指向头结点*/
    x = p->data;                /*保存头结点的数据*/
    Q->front = p->next;         /*将头结点从链上摘下*/
    if(Q->rear==p)               /*原队中只有一个结点，删去后队列变为空，此时队头指针已为空*/
        Q->rear=NULL;
    free(p);
    return x;
}

DataType Front(LinkQueue *Q){
    if(IsEmpty(Q)){
        printf("队列为空");  /*下溢，退出运行*/
        exit(1);
    }
    return Q->front->data;
}


int main(void)
{
	LinkQueue s;
	DataType first,sec;
	Initial(&s);
	Push(&s,'a');
	Push(&s,'b');
	first=Front(&s);
	Pop(&s);
	sec=Front(&s);
	Pop(&s);
    printf("first=%c\n", first);
    printf("sec=%c\n", sec);

    return 0;
}

