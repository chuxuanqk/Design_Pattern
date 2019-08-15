#include <stdlib.h>
#include <stdio.h>

/*循环队列，解决顺序队列假上溢的问题*/
/*舞伴问题,问题描述
假设在周末舞会上，男士们和女士们进入舞厅时，各自排成一队。
跳舞开始时，依次从男队和女队的队头上各出一人配成舞伴。
若两队初始人数不相同，则较长的那一队中未配对者等待下一轮舞曲。
现要求写一算法模拟上述舞伴配对问题。
*/

#define MAX_DANCERS 100     //最多跳舞人数
#define QueueSize  100      //假定预分配的队列空间最多为100个元素  

typedef struct{
    char name[20];
    char sex;           /*性别：'F'表示女性，'M'表示男性*/
}Person;

typedef Person DataType;


typedef struct{
    DataType data[QueueSize];
    int front;
    int rear;
    int count;  /*计数器，记录队中元素总数*/
}CirQueue;


void Initial(CirQueue *Q)
{
    Q->front = Q->rear = 0;
    Q->count = 0;
}


int IsEmpty(CirQueue *Q)
{
    return Q->front==Q->rear;
}


int IsFull(CirQueue *Q)
{
    return Q->rear == QueueSize-1+Q->front;
}

void EnQueue(CirQueue *Q, DataType x)
{
    if(IsFull(Q))
    {
        printf("队列上溢");
        exit(1);
    }
    Q->count++;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%QueueSize;     /*循环意义下将尾指针加1*/
}


DataType DeQueue(CirQueue *Q)
{
    DataType temp;
    if(IsEmpty(Q))
    {
        printf("队列为空");
        exit(1);
    }
    temp = Q->data[Q->front];
    Q->count--;
    Q->front = (Q->front+1)%QueueSize;   /*循环意义下将头指针加1*/

    return temp;
}

// 取队列顶元素
DataType  Front(CirQueue *Q)
{
    if(IsEmpty(Q))
    {
        printf("队列为空");
        exit(1);
    }
    return Q->data[Q->front];
}


void DancePartner(Person dance[], int num)
{// 结构数组dancer中存放跳舞的男女，num是跳舞的人数
    int i;
    Person p;
    CirQueue Mdancers, Fdancers;
    Initial(&Mdancers);     // 男士队列初始化
    Initial(&Fdancers);     // 女士队列初始化
    for(i=0; i<num; i++){ // 依次将跳舞者依其性别入队
        p = dancer[i];
        if(p.sex=='F')
            EnQueue(&Fdancers, P);   // 排入女队
        else if(p.sex=='M')
            EnQueue(&Fdancers, p);  // 排入男队
    }
	printf("舞队是:\n");
	while(!IsEmpty(&Fdancers)&&!IsEmpty(&Mdancers)){
		//依次输入男女舞伴名
		p=DeQueue(&Fdancers);     //女士出队
		printf("%s        ",p.name);//打印出队女士名
		p=DeQueue(&Mdancers);     //男士出队
		printf("%s\n",p.name);    //打印出队男士名
	}
	if(!IsEmpty(&Fdancers)){ //输出女士剩余人数及队头女士的名字
		printf("还有 %d 个女士等下一轮.\n",Fdancers.count);
		p=Front(&Fdancers);  //取队头
		printf("%s will be the first to get a partner. \n",p.name);
	}
	else if(!IsEmpty(&Mdancers)){//输出男队剩余人数及队头者名字
		printf("还有%d 个男士等下一轮.\n",Mdancers.count);
		p=Front(&Mdancers);
		printf("%s will be the first to get a partner.\n",p.name);
	}
}

int main(void)
{
    CirQueue s;
    DataType first, sec;
    Initial(&s);
    EnQueue(&s, 10);
    EnQueue(&s, 20);
    first = Front(&s);
    printf("first=%d\n", first);
    DeQueue(&s);
    sec = Front(&s);
    printf("sec=%d\n", sec);
    DeQueue(&s);

    return 0;
}

