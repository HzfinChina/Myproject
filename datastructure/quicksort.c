#include<stdio.h>
void Swap(int *a, int *b)
{
    int temp = *a;
    *a= *b;
    *b = temp;
}
/* 单边循环法
void quicksort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mark = left, stan = a[left];
    int pos = left;
    for (; pos <= right; pos++)
    {
        if (a[pos] < stan)
        {
            mark++;
            Swap(&a[pos], &a[mark]); //双指针法
        }
    }
    Swap(&a[left], &a[mark]); //让基准数字放在中间，左边都小于基准，右边大于基准
    quicksort(a, left, mark - 1);
    quicksort(a, mark + 1, right);
}
*/

void quicksort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int stan = a[left];
    int temp = left;
    while( left < right)
    {
        if (a[right] < stan)
        {
            a[temp] = a[right];
            temp = right;
            left++;
            if (a[left] > stan)
            {
                a[temp] = a[left];
                temp = left;
                right--;
            }
        }
        else 
            right--;
        a[temp] = stan;
    }
    Swap(&a[temp], &a[left]);
    quicksort(a, left, temp - 1);
    quicksort(a, temp + 1, right);
}

int main()
{
    int a[] = {4,7,3,5,6,2,8,1};
    quicksort(a, 0, 7);
}
