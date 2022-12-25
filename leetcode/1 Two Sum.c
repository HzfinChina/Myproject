#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0;
    for (i = 0; i <=  numsSize-2; i++)
    {
        if (nums[i] > target)
            continue;
        int j;
        for (j = i+1; j <= numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int* ret = (int*)malloc(sizeof(int)*2);
                ret[0] = nums[i];
                ret[1] = nums[j];
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return NULL;

}
