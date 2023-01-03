void quick_sort(int *array, int left, int right){
    if (left >= right)
        return;
    int pivot = array[left];
    int i = left, j = right; 
    while (i < j){
        // fuck! the '=' wasted me lots time to debug
        // don't miss it or it will be trapped in dead cycle
        while(array[j] >= pivot && i < j){
            j--;
        }
        if (i < j)
            array[i++] = array[j];
        while(array[i] < pivot && i < j){
            i++;
        }
        if (i < j)
            array[j--] = array[i];
        
    }
    array[i] = pivot;
    quick_sort(array, left, i);
    quick_sort(array, i+1, right);
}

#include <stdio.h>
#include <time.h>
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
    quick_sort(array, 0, LEN -1);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}
