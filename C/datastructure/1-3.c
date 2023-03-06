#include <stdio.h>
#include <math.h>
void PrintDigit(int num)
{
    printf("%d", num);
}

void PrintOut(float N)
{
    if (fabs(N) > 10){
        PrintDigit(fmod(N, 10));
    }
    else {
        if (fabs(N- fmod(N, 1)) > 0.0001)
        {
            putchar('.');
        }
    }
}

int main()
{

}
