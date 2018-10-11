#ifndef _Queue_h
#define _Queue_h

typedef float ElementType;
typedef struct QueueRecord *Queue;

int IsEmpty( Queue Q );
int IsFull( Queue Q );
Queue CreateQueue(int MaxElements);
void DeposeQueue( Queue Q);
void MakeEmpty( Queue Q );
void Enqueue( ElementType X,Queue Q );
ElementType Front( Queue Q );
void Dequeue( Queue Q );
ElementType FrontAndDequeue( Queue Q );

#endif

#define MinQueueSize (5)

struct QueueRecord{
    int Capacity;
    int Frout;
    int Rear;
    int Size;
    ElementType *Array;
};