void Merge(int *array, int *temp, int left, int right){
    int mid = left + (right - left) / 2;
    int *temppos = temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right){
        if (array[i] < array[j]){
            *temppos++ = array[i++];
        }
        else 
            *temppos++ = array[j++];
    }
    while (i <= mid)
        *temppos++ = array[i++];
    while (j <= right)
        *temppos++ = array[j++];
    for(; left <= right; left++){
        array[left] = *temp++;
    }
}

void Merge_Sort(int *array, int *temp, int left, int right){
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    Merge_Sort(array, temp, left, mid);
    Merge_Sort(array, temp, mid + 1, right);
    Merge(array, temp, left, right);
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LEN 100000
int main()
{
    int array[LEN] = {};
    FILE *fp = fopen("/tmp/s", "r");
    for (int i = 0; i < LEN; i++){
        fscanf(fp, "%d, ", &array[i]);
    }
    clock_t start, end;
    start = clock();
    int *temp = malloc(sizeof(int) * LEN);
    Merge_Sort(array, temp, 0,LEN-1);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
