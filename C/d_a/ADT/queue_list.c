#include "queue_list.h"
struct queue * CreateQueue(int capacity){
    struct queue * retptq = malloc(sizeof(struct queue));
    retptq->front = 0;
    retptq->rear= -1;
    retptq->array = malloc(sizeof(int)*capacity);
    retptq->capacity = capacity;
    retptq->size = 0;
    return retptq;
}

void MakeEmpty(struct queue * ptq){
    ptq->capacity = 0;
    ptq->rear = 0;
    ptq->front = 0;
    ptq->size = 0;
}

void DisposeQueue(struct queue *ptq){
    free(ptq->array);
    free(ptq);
}

void Enqueue(struct queue *ptq, int data){
    // check if the queue is full
    if (ptq->size == ptq->capacity)
        exit(-10);
    if (ptq->rear == ptq->capacity - 1){
        ptq->rear = 0;
    }
    else 
        ptq->rear ++;
    ptq->array[ptq->rear] = data;
    ptq->size++;
}



// let the front element get out
int Dequeue(struct queue * ptq){
    // if the queue is empty return error
    if (ptq->size == 0)
        exit(-20);
    int retnum = ptq->array[ptq->front];
    if (ptq->front == ptq->capacity-1)
        ptq->front = 0;
    else 
        ptq->front++;
    ptq->size--;
    return retnum;
}
