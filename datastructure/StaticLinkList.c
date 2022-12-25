#include<stdio.h>
#define MAXSIZE 1000
typedef struct
{
    int data;
    int cur;  /* 游标(Cursor)，为0时表示无指向*/
}StaticLinkList;
int main()
{
    StaticLinkList list[MAXSIZE];
    return 0;
}
int InitList(StaticLinkList space[])
{
    int i;
    for (i=0; i < MAXSIZE-1; i++)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;  
    return 0;
}
//让最后一位存放的下标为第一个插入元素的下标，相当于头结点
/*数组第一个元素的cur存放第一个空闲空间的下标 */
int Malloc(StaticLinkList space[])
{
    int i = space[0].cur;
    if (space[0].cur)
        space[0].cur = space[i].cur;
    return i;
}
int Input(StaticLinkList space[])
{
    int i=0 ,pointer = 0,max;
    puts("how many data?");
    scanf("%d",&max);
    do
    {
        i++;
        scanf("%d", &space[i].data);
    }while(i < max-1);

        

        
    

