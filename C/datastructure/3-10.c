#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct man{
    int next;
};

int Josephus(int M, int N){
    struct man *manarr = malloc(sizeof(struct man) * N);
    int i, nowindex = 0, size = N;
    int gap = M;

    // circular array
    for (i = 0; i < N; i++){
        manarr[i].next = i+1;
    }
    manarr[N-1].next = 0;

    while(size!=1){
        for (i = 0; i < M-1; i++){
            nowindex = manarr[i].next;
        }
        manarr[nowindex].next = manarr[manarr[nowindex].next].next;
        nowindex = manarr[nowindex].next;
        size--;
    }
    return nowindex + 1;
}

#include<time.h>
int main()
{
    clock_t start, end;
    start = clock();
    printf("%d\n", Josephus(888, 100000));
    end = clock();
    printf("run time, %lf", (double)(end - start) / CLOCKS_PER_SEC);
}
