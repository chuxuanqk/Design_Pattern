#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define OK    1
#define ERROR 0
#define TRUE  1
#define FALSE 0

typedef int Status; /*Status是函数的类型，其值是函数结果状态代码，如OK等*/

#if CHAR
    typedef char TElemType;
    TElemType Nil=' ';  /*设字符型以空格符为空*/
#else
    typedef int TElemType;
    TElemType Nil=0;    /*设整型以0位空*/
#endif

#define MAX_TREE_SIZE 100   /*二叉树的最大节点数*/
typedef TElemType SqBiTree[MAX_TREE_SIZE];  /*0号单位存储根节点*/

Status InitBiTree(SqBiTree T){
    /*构造空二叉树T,因为T是固定数组，不会改变，故不需要&*/
    int i;
    for(i=0; i<MAX_TREE_SIZE; i++)
        T[i] = Nil; /*初值为空*/
    return OK;
}


Status CreateBiTree(SqBiTree T){
    /*按层序次序输入二叉树中节点的值(字符型或整型)，构造顺序存储的二叉树T*/
    int i=0;
#if CHAR
    int l;
    char s[MAX_TREE_SIZE];
    printf("请按层序输入节点值(字符)，空格表示空节点，节点数≤%d:\n", MAX_TREE_SIZE);
    gets(s);    /* 输入字符串 */
    l = strlen(s);
    for(; i<1; i++){
        T[i]=s[i];
        if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil){  /*此节点(不空)无双亲且不是根*/
            printf("出现无双亲的非根节点:%d\n", T[i]);
            exit(ERROR);
        }
    }
    for(i=l; i<MAX_TREE_SIZE; i++)      /*将空赋值为T的后面的结点*/
        T[i]=Nil;
#else
    printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n",MAX_TREE_SIZE);
    while(1){
        scanf("%d", &T[i]);
        if(T[i]==999)
            break;
        if(i!=0&&T[(i+1)/2-1]==Nil&&T[i]!=Nil){
            printf("出现无双亲的非根结点%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while(i<MAX_TREE_SIZE){
        T[i]=Nil;       /*将控制*/
        i++;
    }
#endif
    return OK;
}


Status BiTreeeEmpty(SqBiTree T){
    /*初始条件: 二叉树T存在 */
    /*操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
    if(T[0]==Nil)   /*根结点为空，则树空*/
        return TRUE;
    else
        return FALSE;
}

int BiTreeDepth(SqBiTree T){
    /*初始条件: 二叉树T存在。
    操作结果: 返回T的深度*/
    int i,j=-1;
    for(i=MAX_TREE_SIZE-1; i>=0; i--)
        if(T[i]!=Nil)
            break;
    i++;    /*为便于计算*/
    do
        j++;
    while(i>=pow(2, j));
    return j;
}

Status Root(SqBiTree T, TElemType *e){
    /* 初始条件: 二叉树T存在 
        操作结果: 当T不空, 用e返回T的根，返回OK; 
                        否则返回ERROR, e无定义*/
    if(BiTreeeEmpty(T)) /* T空 */
        return ERROR;
    else{
        *e=T[0];
        return OK;
    }
}

int main(void)
{
    Status i;
    TElemType e;
    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    i=Root(T,&e);
    if(i)
        printf("二叉树的根为：%d\n",e);
    else
        printf("树空，无根\n");
}


