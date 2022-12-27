#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
typedef struct stack
{
    int data;
    struct stack* down;
}Stack;
Stack* Push(int number, Stack* stackhead)
{
    Stack* newhead = (Stack*)malloc(sizeof(Stack));
    newhead -> down = stackhead;
    newhead -> data = number;
    return newhead;
}
int Pop(Stack* stackhead)
{
    int retnum = stackhead->data;
    stackhead = stackhead->down;
    free(stackhead);
    return retnum;
}

void Swap(void* pvar1, void* pvar2, size_t size)
{
    void *temp = malloc(size);
    assert(temp != NULL);
    memcpy(temp, pvar2, size);
    memcpy(pvar2, pvar1, size);
    memcpy(pvar1, temp, size);
    free(temp);
}

void BubbleSort(int* array, int size)
{
    bool is_changed = true;
    while (is_changed)
    {
        is_changed = false;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (array[i] < array[j])
                {
                    Swap(&array[i], &array[j], sizeof(int));
                    is_changed = true;
                }
                else 
                    break;
            }
        }
    }
}

float Find(int N){
    clock_t start, end;
    start = clock();
    int numlist[N];
    for (int i = 0; i < N; i++){
        numlist[i] = rand();
    }
    BubbleSort(numlist, N);
    end = clock();
    return (end - start);
}

int main()
{
    int Nlist[3] = {100,1000,10000};
    srand((unsigned)time(NULL));
    for (int i = 0; i < 3; i++){
        printf("%f /%lds\n", Find(Nlist[i]), CLOCKS_PER_SEC);
    }
}
