void insertion_sort(int *array, int size){
    int i, j, temp;
    for (i = 0; i < size; i++){
        temp = array[i];
        for (j = i; j > 0 && array[j-1] > temp; j--){
            array[j] = array[j-1];
        }
        array[j] = temp;
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
    clock_t start, end;
    start = clock();
    insertion_sort(array, LEN);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
