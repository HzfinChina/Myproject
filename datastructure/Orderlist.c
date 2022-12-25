#include <stdio.h>
#include <stdlib.h>
#define ListIniSize  100
typedef int ElemType ;
typedef struct OrderedList
{
    ElemType *elem;
    int length;    // 当前在整个表中的位置  类似于数组中的下标
    int listsize;    //当前分配的储存容量（以sizeof(ElemType))为单位
}LIST; 
int IniList (LIST *L)
{
    L-> elem= (ElemType *)malloc(ListIniSize * sizeof(ElemType));
    L->length = 0;
    L->listsize = ListIniSize;
    return 0;
}
void InputData(LIST *L)
{
    int i, n; 
    puts("input how many data you want to input");
    scanf("%d",&n);
    L -> length = n;
    for (i = 0 ;i< n; i++)
    {
        scanf("%d",&(L->elem [i]));
    }
}
void PrintList(LIST *L)
{
    int i ;
    LIST *pL = L;
    for (i = 0;i< L->length; i++)
    {
        printf("%d\n", (L->elem)[i]);
    }
}
/* 在线性表第i个位置之前插入元素 e*/
int ListInsert(LIST *L, int i,ElemType e)
{
    int *p, *q;
    if (i <=1 || i> L->length) return -1;
    q = &((L->elem) [i-1]);
    for ((p = &(L ->elem[L->length -1])); p>=q; p--) *(p+1) =*p;
    *q = e;
    L -> length ++;
}
int ListDelete(LIST *L,int i)
{
    int *q = &L-> elem [i-1];
    int *end;
    end = L -> elem + L -> length -1;
    for (;q< end;q++)*q = *(q+1);
    L->length --;
    return 1;
}
int main()
{
    LIST L;
    IniList( &L);
    puts("1");
    InputData( &L);
    PrintList(&L);
    ListInsert(&L, 2, 999);
    PrintList(&L);
    puts("");
    ListDelete(&L,2);
    PrintList(&L);
}
        
