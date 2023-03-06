#include<stdio.h>
typedef struct queue
{
    int head,tail;
    int data[100];
}QUEUE;
int main()
{
    struct queue q;
    int i;
    q.head = 1;
    q.tail = 1;
    puts("input number");
    for ( i=1; i<=9; i++)
    {
        scanf("%d ",&q.data[q.tail]);
        q.tail ++;
    }
    while(q.head < q.tail)
    {
        printf("%d",q.data[q.head]);
        q.head ++;
        q.data[q.tail] = q.data[q.head];
        q.head++;
        q.tail ++;
    }
    return 0;
}
