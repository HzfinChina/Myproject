void bubble_sort(int *array, int size){
    _Bool issorted = 1;
    int i, temp;
    while(issorted){
        issorted = 0;
        for (i = 0; i < size - 1; i++){
            if (array[i] > array[i+1]){
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                issorted = 1;
            }
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
    clock_t start, end;
    start = clock();
    bubble_sort(array, LEN);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
