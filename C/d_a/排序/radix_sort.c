#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "../ADT/queue_list.h"
#define MIN 0
#define MAX 999
int powi(int base, int exponent){
    int ret = 1;
    for (int i = 0; i < exponent; i++){
        ret *= base;
    }
    return ret;
}

void radix_sort(int *array, int size){
    int i = 0, j = 0, k = 0;
    int digitnum = 0;
    struct queue* quearr[10];
    for (i = 0; i < 10; i++){
        quearr[i] = CreateQueue(10);
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < size;j++){
            digitnum = (array[j] % (int)powi(10, i + 1)) / powi(10, i);
            Enqueue(quearr[digitnum], array[j]);
        }
        k=0;
        for (j = 0; k < 10;){
            while(! isEmpty(quearr[k])){
                array[j++] = Dequeue(quearr[k]);
            }
            k++;
        }
    }
}


#include <stdio.h>
#include <time.h>
#define LEN 10
int main()
{
    int array[LEN] = {};
    FILE *fp = fopen("/tmp/s", "r");
    for (int i = 0; i < LEN; i++){
        fscanf(fp, "%d, ", &array[i]);
    }
    fclose(fp);
    clock_t start, end;
    start = clock();
    radix_sort(array, LEN);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
