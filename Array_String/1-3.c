#include <stdio.h>

// 一维数组的高级应用, 计算数的阶乘
// 用数组存储多位数字，解决计算超出类型最大值
void Array_apply()
{
    int Data[40];
    int Digit;
    int i,j,r,k;
    int N;

    for(i=1; i<41; i++)
        Data[i]=0;

    Data[0] = 1;
    Data[1] = 1;
    Digit = 1;
    printf("Enter a number what you want to calculus:");
    scanf("%d", &N);
    for(i=1; i<N+1; i++)
    {
        for(j=1; j<Digit+1; j++)
            Data[j] *=i;
        for(j=1; j<Digit+1; j++)
        {
            if(Data[j]>10)
            {
                for(r=1; r<Digit+1; r++)
                {
                    if(Data[Digit]>10)
                        Digit++;
                    Data[r+1] += Data[r]/10;
                    Data[r] = Data[r]%10;  
                }
            }
        }
        printf("%d!=", i);
        for(k=Digit; k>0; k--)
            printf("%d", Data[k]);
        printf("\n"); 
    }
}


int cul(int x, int y)   /*求杨辉三角形中第x行第y列的值*/
{
    int z;
    if((y==1)||(y==x+1))
        return 1;        /*若为x行的第1行或第x+1列， 则输出1*/
    z = cul(x-1, y-1)+cul(x-1, y);      /*否则，其值位前一行中第y-1列与y列值之和*/
    return z;
}


// 显示杨辉三角
void  ShowYanghuiTriangle()
{
    int i, j, n=13;
    printf("N=");
    while(n>12)
        scanf("%d", &n);   /*控制输入正确的值以保证屏幕显示的图形正确*/
    for(i=0; i<=n; i++)    /*控制输出N行*/
    {
        for(j=0; j<24-2*i; j++)
            printf(" ");        /*控制输出第i行前面的空格*/
        for(j=1; j<i+2; j++)
            printf("%4d", cul(i, j));    /*输出第i行的第j个值*/
        printf("\n");
        
    }
}



int main()
{
    ShowYanghuiTriangle();
    return 0;
}
