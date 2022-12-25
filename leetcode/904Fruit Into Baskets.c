#include <stdio.h>
#include <stdlib.h>

typedef struct typequeue
{
    int type;
    struct typequeue* next;
}Queue;

int In(Queue* node, int type)
{
    if (type != node->type)
        return 0;
    else 
        return 1;
}

Queue* Push(Queue* node, int type)
{
    Queue* head = (Queue*)malloc(sizeof(Queue));
    head->type = type;
    head->next = node;
    return head;
}
Queue* Pop(Queue* head)
{
    Queue* temp = head -> next;
    free(head);
    return temp;
}

int totalFruit(int* fruits, int fruitsSize)
{
    int left = 0, right = 0, sum = 0;
    Queue* head = (Queue*)malloc(sizeof(Queue));
    head -> type = fruits[0]; 
    head -> next = NULL;
    while (1)
    {
        if (right <= fruitsSize - 2)right++;
        else 
        {
            sum = right-left + 1> sum? right-left+1:sum;
            break;
        }
        if (head->next == NULL)
        {
            if (head ->type == fruits[right])
            {
                continue;
            }
            else 
            {
                head = Push(head, fruits[right]);
                continue;
            }
        }
        else //如果head ->next不为空的话
        {
            if (In(head, fruits[right]) || In(head->next, fruits[right]))
            {
                continue;
            }
            else 
            {
                sum = right - left > sum ? right - left : sum;
                while (In(head->next, fruits[left]) ) //因为采用的是队列形式，所以只需要比较先进去的元素就可以
                    left ++;
                int temp = head->type;
                head->type = fruits[right];
                head->next->type = temp;
            }
        }
    }
    return sum;
}

int main()
{
    int fruits[] = {3,3,3,1,2,1,1,2,3,3,4};
    int fruitsSize = 11;
    printf("%d",totalFruit(fruits, fruitsSize));
}
