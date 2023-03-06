#include <stdlib.h>
#include <string.h>
int * counting_sort(int *array, int size){
    int max = 0, min = 0;
    int i, j;
    /* Find max and min element in array */
    for (i = 0; i < size; i++){
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    int * posarray = malloc(sizeof(int) * size);
    memset(posarray, 0, size * sizeof(int));
    int * retarray = posarray;
    int * temparray = malloc(sizeof(int) * (max - min + 1));
    memset(temparray, 0, (max -min + 1) * sizeof(int));
    
    for (i = 0; i < size; i++){
        temparray[array[i] - min] ++;
    }
    for (i = 0; i < max - min + 1; i++){
        for (j = 0; j < temparray[i]; j++){
            *posarray = i + min;
            posarray++;
        }
    }
    return retarray;
}

int main(){
    int array[10] = {2,5,1,9,10,-3,4,6,7,9};
}
