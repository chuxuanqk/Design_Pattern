#include <stdio.h>

int Strlen(char *s)
{
    int i;
    for(i=0; s[i]!='\0';)
        i++;

    return i;
}

char *strcpy(char *s1, char *s2)
{
    int i;
    for(i=0; s2[i]!='\0'; i++)
        s1[i] = s2[i];
    s1[i]='\0';
	
    return s1;
}

/*cahr replace*/
char *strrep(char *s1, char *s2, int pos)
{
    int i,j;
    pos--;
    i=0;
    // 采用数组下标的形式访问修改，不需要指针，附加i作为浮标
    for(j=pos; s1[j]!='\0'; j++)
        if(s2[i]!='\0')
        {
            s1[j] = s2[i];
            i++;
        }else{
            break;
        }
    return s1;
}

char *strdel(char *s, int pos, int len)
{
    int i;
    pos--;
    for(i=pos+len; s[i]!='\0'; i++)
        s[i-len]=s[i];
    s[i-len]='\0';
    return s;
}

int strcmp(char *s1, char *s2)
{
    int i,j;
    for(i=0; s1[i]==s2[i]; i++)
        if(s1[i]=='\0'&&s2[i]=='\0')
            return 0;
    if(s1[i]>s2[i])
        return 1;
    return -1;    
}


/*字符串抽取*/
char *substr(char *s, int pos, int len)
{
    char s1[50];
    int i,j,endpos;
    pos--;
    endpos=pos+len-1;
    for(i=pos, j=0; i<=endpos; i++,j++)
        s1[j] = s[i];

    s1[len] = '\0';
    
    return s1;
}


/*字符串分割*/
int partition(char *s1, char *s2, int pos)
{
    int i, j;
    i = pos;
    while(s1[i]==' ')
        i++;
    if(s1[i]!='\0')
    {
        j=0;
        while(s1[i]!='\0'&&s1[i]!=' ')
        {
            s2[j] = s1[i];
            i++;
            j++;
        }
        s2[j]='\0';
        return i;
    }else
    {
        return -1;
    }
}

/*#include <string.h>
#define MAX_SIZE  100

void insert(char *s, char *t, int i)
{
    char string[MAX_SIZE], *temp = string;
    if(i<0||i>Strlen(s))
    {
        printf("插入位置越界！\n");
        exit(i);
    }
    if(!Strlen(s))
        strcpy(s, t);
    else if(strlen(t)){
        strncpy(temp, s, i);
        strcat(temp, t);
        strcat(temp, (s+i));
        strcpy(s, temp);
    }
}

/*
/*字符串匹配*/
int nfind(char *B, char *A)
{
    int i, j, start=0;
    int lasts = Strlen(B)-1;
    int lastp = Strlen(A)-1;
    int endmatch = lastp;
    for(i=0; endmatch<=lasts; endmatch++, start++)
    {
        if(B[endmatch] == A[lastp])
            for(j=0, i=start; j<lastp&&B[i]==A[j];)
                i++, j++;
        if(j==lastp)
            return (start+1);
    }
    if(start==0)
        return -1;
}


void catstr(char *des, char *sour)
{
    int end=Strlen(des);
    int i,j,num;
    num = Strlen(sour);
    for(i=end, j=0; j<num; i++,j++)
        des[i] = sour[j];
    // des[i+1] = '\0';
    // printf("des path：%p\n", &des[i]);
}


int main()
{
    char s[] = "Sit down";
    char t[] = " please!";
    catstr(s, t);
    printf("%s\n", s);
    printf("%p\n", &t);
}



