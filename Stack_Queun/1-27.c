#include "stdio.h"
#include "stdlib.h"

// 进制转换问题

#define StackSize 100    /*假定预分配的栈空间最多为100个元素*/

typedef int DataType;      /*假定栈元素的数据类型为字符*/  
typedef struct{
    DataType data[StackSize];
    int top;
}SeqStack;

/*置空栈*/
void Initial(SeqStack *S)
{
    S->top = -1;
}

/*判栈空*/
int IsEmpty(SeqStack *S)
{
    return S->top == -1;
}

/*判断栈满*/
int IsFull(SeqStack *S)
{
    return S->top == StackSize-1;
}

/*进栈*/
void Push(SeqStack *S, DataType x)
{
    if(IsFull(S)){
        printf("栈上溢");
        exit(1);
    }
    S->data[++S->top] = x; /*栈顶指针加1后将x入栈*/
}

/*出栈*/
DataType Pop(SeqStack *S)
{
    if(IsEmpty(S)){
        printf("栈为空");    /*下溢，退出运行*/
        exit(1);
    }
    return S->data[S->top--];    /*栈顶元素返回后将栈顶指针减1*/
}

/*取栈顶元素*/
DataType Top(SeqStack *S)
{
    if(IsEmpty(S)){
        printf("栈为空");
        exit(1); 
    }
    return S->data[S->top];
}


// 进制转换问题
void MultiBaseOutput(int N, int B)
{/*假设N是非负的十进制整数，输出等值的B进制数*/
    int i;
    SeqStack S;
    Initial(&S);
    while(N){   /*从右向左产生B进制的各位数字，并将其进栈*/
        Push(&S, N%B);
        N = N/B;
    }
    while(!IsEmpty(&S)){   /*栈非空时退栈输出*/
        i = Pop(&S);
        printf("%d", i);
    }
    printf("\n");
}

int main()
{
    int N;
    int B;
    printf("N  and  B:");
    scanf("%d,%d", &N, &B);
    while(1){
        MultiBaseOutput(N, B);
        printf("N  and  B:");
        scanf("%d,%d", &N, &B);
    }
}


