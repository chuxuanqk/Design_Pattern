/*求矩阵A中的马鞍点*/
/*
鞍点（Saddle point）在微分方程中，沿着某一方向是稳定的，
另一条方向是不稳定的奇点，叫做鞍点。
在矩阵中，一个数在所在行中是最大值，在所在列中是最小值，则被称为鞍点。
*/

#include <stdio.h>

#define n 3
#define m 3

void Get_Saddle(int A[m][n])
{
    int i,j,flag=0,min,k;
    for(i=0; i<m; i++){
        for(min=A[i][0], j=0; j<n; j++){
            if(A[i][j]<min){
                min=A[i][j];      /*求i行中的最小值*/
            }
        }
        for(j=0; j<n; j++){
            if(A[i][j]==min){     /*判断这些最小值是否是鞍点*/
                for(flag=1, k=0; k<m; k++){
                    if(min<A[k][j]){
                        flag = 0;
                    }
                }
                if(flag){
                    printf("Found a saddle element!\nA[%d][%d]=%d",i,j,A[i][j]);
                }
            }
        }
    }
    printf("\n");
}


int main()
{
    int A[m][n] = {{1,2,3},{4,5,6},{7,8,9}};
    /*初始化A[n]*/
    Get_Saddle(A);
}

