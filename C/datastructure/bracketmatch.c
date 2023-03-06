#include<stdio.h>
#include "orderStack.c"
void CheckandPush(SqStack *pst,int num)
{
    if (num + *(pst->top) == 10)
    {
        Pop(pst);
        return;
    }
    Push(pst, num);
}
int main()
{
    char *str;
    char test;
    SqStack stack;
    SqStack *pst = &stack;
    Init(pst);
    printf("inputs string");
    scanf("%s",str);
    do
    {
        switch(*str)
        {
            case '(':
                CheckandPush(pst,1);
                break;
            case ')':
                CheckandPush(pst,9);
                break;
            case '[':
                CheckandPush(pst,2);
                break;
            case ']':
                CheckandPush(pst,8);
                break;
            case '{':
                CheckandPush(pst,3);
                break;
            case '}':
                CheckandPush(pst,7);
                break;
            default: break;
        }
        str++;
    }while(*str != '\0');
    if (pst->stacksize != 0)
    {
        puts("not matching!");
    }
    else
        puts("all matching");
    
    return 0;
}
