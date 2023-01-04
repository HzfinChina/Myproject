struct queue {
    int capacity;
    int size;
    int front, rear;
    int *array;
};

struct queue * CreateQueue(int size);
void MakeEmpty(struct queue * ptq);
void DisposeQueue(struct queue *ptq);
void Enqueue(struct queue *ptq, int data);
int Dequeue(struct queue * ptq);
