#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int Compare(char a, char b)
{
    if (a==b)return 1;
    return 0;
}

char* SlicetoI(char*p ,int i)
{
    char*str = (char*)malloc(sizeof(char)*(i+1));
    int m;
    for(m = 0;m<= i;m++)
    {
        *(str+m) = p[m];
    }
    return str;
}

int Slice(char*p, int k) //切取前缀和后缀并且比较是否相等 相等返回0
{
    char List[2][k];
    int len = strlen(p);
    int i;
    for (i = 0;i<=k-1;i++)
    {
        List[0][i] = p[i];
    }
    for (i = 0;i<=k-1;i++)
    {
        List[1][i] = p[len-k+i];
    }
    return strncmp(List[0],List[1],k);
}

int* FindMaxk(char *p)
{
    int len = strlen(p);
    int *next = (int*)malloc(len*sizeof(int));
    int i = 0,j,flag;
    next[0] = 0;
    for (i = 1;i <= len-1;i++)
    {
        char *str = SlicetoI(p,i);
        for(j = i; j>= 1;j--) //j是长度，字符串p[0]~p[i]长度为i+1
        {
            if((flag = Slice(str, j)) ==0)break;
        }
        next[i] = j;
    }
    return next;
}

int Normal(char *s, char *p)
{
    char *hs = s;
    int flag = 0, pos = 0;
    int lenp = strlen(p);
    while(1)
    {
        while(1)
        {
            if (hs[pos] == p[pos])
            {
                pos++;
                if(p[pos] == '\0')return 1;
                continue;
            }
            else
            {
                pos = 0;
                if (hs[lenp] == '\0')return -1;
                break;
            }
        }
        hs++;
    }
}

int KMP(char *s, char *p)
{
    char *hs = s;
    int flag = 0, pos = 0;
    int len = strlen(p);
    int *next = FindMaxk(p);
    while(1)
    {
        if(hs[pos] == p[pos])
        {
            pos++;
            if(p[pos] == '\0')return 1;
            continue;
        }
        else
        {
            if (strlen(hs) <= len)return -1;
            if(pos == 0)
            {
                hs++;
                continue;
            }
            hs +=(pos-next[pos-1]);
            pos-=(pos-next[pos-1]); //也即next[pos-1]
        }
    }
}

int main()
{
    KMP("3453345134534","12345");
}
