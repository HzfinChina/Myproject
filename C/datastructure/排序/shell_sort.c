void shell_sort(int *array, int size){
    int i, j, temp;
    int gap;
    for (gap = size / 2; gap > 0; gap/=2){
        for (i = gap; i < size; i++){
            temp = array[i];
            for (j = i; j-gap >= 0 && array[j-gap] > temp; j -= gap){
                array[j] = array[j-gap];
            }
            array[j] = temp;
        }
    }
}

#include <stdio.h>
#include <time.h>
#define LEN 10000
int main()
{
    int array[LEN] = {};
    FILE *fp = fopen("/tmp/s", "r");
    for (int i = 0; i < LEN; i++){
        fscanf(fp, "%d, ", &array[i]);
    }
    clock_t start, end;
    start = clock();
    shell_sort(array, LEN);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
