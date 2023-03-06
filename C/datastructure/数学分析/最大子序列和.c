#include <stdio.h>

int MaxSubarraySum(int *array, int size){
    int i;
    int sum = 0;
    int min = 0, max = array[0]; // 让max = array[0]是为了防止整个array全是负数的情况
    int delta;
    
    for (i = 0; i < size; i++){
        sum += array[i];
        delta = sum - min;
        if (delta > max)
            max = delta;
        if (sum < min)
            min = sum;
    }
    return max;
}

int main()
{
    int array[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d", MaxSubarraySum(array, 9));
}
