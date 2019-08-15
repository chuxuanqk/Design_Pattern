#include <stdio.h>
#include <stdlib.h>



typedef char datatype;
typedef struct node{
    datatype data;
    struct node *next;
}listnode;

typedef listnode *linklist;
// listnode *p;

/*头插法创建链表*/
linklist createlist(void)
{
    char ch;
    linklist head;      // 创建头结点
    listnode *p;
    head = NULL;
    ch = getchar();
    while(ch!='\n'){
        p = (listnode*)malloc(sizeof(listnode));    /*分配空间*/
        p->data = ch;   /*数据域赋值*/
        p->next = head; /*指定后继指针*/
        head = p;       /*head指针指定到新插入的结点上*/
        ch=getchar();
    }
    return (head);
}


/*尾插法创建链表*/
linklist creater()
{
    char ch;
    linklist head;
    listnode *p, *r;
    head=NULL;
    r=NULL;
    while(ch=getchar()!='\n'){
        p=(listnode *)malloc(sizeof(listnode));
        p->data=ch;
        if(head==NULL)
            head=p;     /*head 指向第一个插入结点*/
        else
            r->next=p;  /*插入到链表尾部*/
        r=p;    /*r指向最新结点，即最后结点*/
    }
    if(r!=NULL)
        r->next=NULL;   /*链表尾部结点的后继指针指定为空*/
    return head;
}

/*按序号查找结点*/
listnode *getnode(linklist head, int i)
{
    int j=0;
    listnode *p=head;
    while(p->next && j<i){  /*遍历第i个结点前的所有结点*/
        p = p->next;
        j++;
    }
    if(i==j){
        printf("%c\n", p->data);
        return p;
    }else
        return NULL:
}


int main(void)
{
    linklist newlist=createlist();
    listnode *node;
    int i=0;

    do{
        printf("%c\n", newlist->data);
        newlist=newlist->next;
    }while(newlist!=NULL);
    printf("\n");

}