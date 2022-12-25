#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int array[100];
}NumberArray;


int a = {1,2,3};

int *retarray(int *inarray, int size)
{
    for (int i = 0; i < size; i++)
    {
        inarray[i] ++;
    }
}
