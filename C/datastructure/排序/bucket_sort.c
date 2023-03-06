#include <stdlib.h>
#include "quick_sort.c"
#define MAX 100
#define MIN 0
struct bucket {
    int data;
    struct bucket * next;
};


void Push(struct bucket * ptbucket, int data){
    // while(ptbucket->next != NULL && ptbucket->next->data < data)
    //     ptbucket = ptbucket->next;
    struct bucket * newnode = malloc(sizeof(struct bucket));
    newnode -> data = data;
    newnode->next = ptbucket ->next;
    ptbucket->next = newnode;
}

int SortList(struct bucket * node, int * temp){
    int len = 0;
    int i;
    struct bucket *head = node;
    for (len = 0; node->next!=NULL; len++){
        temp[len] = node->next->data;
        node = node->next;
    }
    quick_sort(temp, 0, len-1);
    return len;
}

void bucket_sort(int *array, int size){
    int i, j;
    int bucket_size;
    int bucket_arrage = 100;
    int bucket_num = (MAX - MIN) / bucket_arrage;
    int *temp = malloc(sizeof(int)*size);
    // initiate pointer array
    struct bucket **ptbucketarr = malloc(sizeof(struct bucket*) * bucket_num);
    for (i = 0; i < bucket_num; i++){
        // assign address for each element, or it will be 0x0
        ptbucketarr[i] = malloc(sizeof(struct bucket*));
        ptbucketarr[i] ->next = NULL;
    }
    for (i = 0; i < size; i++){
        Push(ptbucketarr[(array[i] - MIN)/bucket_arrage], array[i]);
    }
    for (i = 0; i< bucket_num; i++){
        bucket_size = SortList(ptbucketarr[i], temp);
        for (j = 0; j < bucket_size; j++){
            *array++ = temp[j];
        }
    }
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
    fclose(fp);
    clock_t start, end;
    start = clock();
    bucket_sort(array, LEN);
    for (int i = 0; i < LEN; i++)
        printf("%d ", array[i]);
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f",duration);
}

