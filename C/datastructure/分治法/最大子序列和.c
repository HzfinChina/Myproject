#include <stdio.h>
#include <stdlib.h>

int MaxofThree (int a, int b, int c){
    if (a >= b){
        if (c >= a)
            return c;
        else 
            return a;
    }
    else {
        if (c >= b)
            return c;
        else 
            return b;
    }
}

int MaxSubArraysum(int *array, int left, int right){
    if (left == right){
        return array[left];
    }
    int i;
    int mid = left + (right - left) / 2;
    int leftmaxsum = MaxSubArraysum(array, left, mid);
    int rightmaxsum = MaxSubArraysum(array, mid + 1, right);


    int leftsum = 0, rightsum = 0;
    int midtoleftmax = 0, midtorightmax = 0;
    // 计算从array[mid]往left的最大值
    for (i = mid; i >= left; i--){
        leftsum += array[i];
        midtoleftmax = leftsum > midtoleftmax ? leftsum : midtoleftmax;
    }

    // 计算从array[mid + 1]往 right 的最大值
    for (i = mid + 1; i <= right; i++){
        rightsum += array[i];
        midtorightmax = rightsum > midtorightmax ? rightsum : midtorightmax;
    }

    return MaxofThree(leftmaxsum, rightmaxsum, midtoleftmax+midtorightmax);
}

int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int b =MaxSubArraysum(a, 0, 8);
    printf("%d", b);
}
