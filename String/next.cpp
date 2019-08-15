#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH  200
typedef  char SString[MAXLENGTH+1];   // 0号单元存放串的长度 


void StrAssign(SString T, char *chars)
{
	int i ;
	T[0] = char(strlen(chars));

	// 拷贝串 
	for(i=1; i<=T[0]; i++)
	{
		T[i] = chars[i-1];
		//printf("T[%d]=%c\r\n", i, T[i]);
	}

}

void get_nextval(SString T, int *nextval){
	int i=1;
	nextval[1] = 0;
	int j=0;
	
	while(i<=T[0]){
		if(j==0 || T[i]==T[j]){
			++i; ++j;
			if(T[i] != T[j])   nextval[i] = j;
			else  nextval[i] = nextval[j];
		}else j = nextval[j];
		//printf("nextval[%d]=%d\r\n", j, nextval[j]);
	}	
}

void get_next(SString T, int *next){
	int i=1;
	next[1]=0;
	int j=0;
	while(i<=T[0]){
		if(j==0||T[i]==T[j]){
			++i; ++j; next[i]=j;
			}else	j=next[j];
		}
}

int KMP(SString S, SString T, int next[], int pos){
	int i=pos;
	int j=1;
	
	while(i<=S[0]&&j<=T[0]){
		if(j==0||S[i]==T[j]){
			++i;
			++j;
		}else{
			j=next[j];
		}
	}
		if(j>T[0])
			return i-T[0];
		else
			printf("fail= %d\r\n", j);
			return 0;
}


int main(void)
{
	SString temp;
	SString Stemp;
	int nextval[MAXLENGTH];
	int i=0;
	int pos=0;
	char *chars = "abcd";
	char *S = "baacababacd";
	
	StrAssign(temp, chars);
	StrAssign(Stemp, S);
	get_nextval(temp, nextval);
	//get_next(temp, nextval);
	pos = KMP(Stemp, temp, nextval, 1);
	printf("pos=%d\r\n", pos);
	for(i=1; i<=temp[0]; i++)
		printf("nextval[%d]=%d\r\n", i, nextval[i]);
	
	return 0;
}




