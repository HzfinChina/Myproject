#include <stdio.h>
#include <stdlib.h>

int minSubArrayLen(int target, int* nums, int numsSize){
    int min = numsSize + 1;
    int left = 0, right = 0, sum = 0;
    while (right < numsSize)
    {
        sum += nums[right];
        while (sum >= target)
        {
            min = right - left + 1 < min ? right - left + 1:min;
            sum -= nums[left];
            left ++;
        }
        right ++;
    }
    return min == numsSize+1? 0:min;
}

int main()
{
    int target = 7;
    int nums[] = {2,3,1,2,4,3};
    int numsSize = 6;
    int min = minSubArrayLen(target, nums, numsSize);
    printf("%d", min);
}
