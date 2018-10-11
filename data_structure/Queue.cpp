#include "Queue.h"
#include <stdlib.h>
#include<iostream>
using namespace std;

int IsEmpty( Queue Q){
    return Q->Size == 0;
}

int IsFull( Queue Q ){
    return Q->Size >= Q->Capacity;
}
Queue CreateQueue(int MaxElements){
    Queue Q;
    Q = (Queue)malloc(sizeof( struct QueueRecord ));
    if (Q==NULL){
        cout<<"Out of Space!!"<<endl;
    }
    if (MaxElements<MinQueueSize){
        cout<<"Size is too small for queue"<<endl;
    }
    Q->Array = (ElementType*)malloc(sizeof(ElementType)*MaxElements);
    if (Q->Array==NULL)
        cout<<"Out of Space!!"<<endl;
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
}
void MakeEmpty( Queue Q ){
    Q->Size=0;
    Q->Frout=1;
    Q->Rear=0;
}
void Enqueue( ElementType X,Queue Q ){
    if(IsFull(Q))
        cout<<"Full queue"<<endl;
    else{
        Q->Size++;
        Q->Rear = Succ(Q->Rear ,Q);
        Q->Array[Q->Rear] = X;
    }
}

static int Succ(int Value,Queue Q){
    if(++Value == Q->Capacity)
        Value = 0;
    return Value;
}

ElementType Front( Queue Q ){
    if(IsEmpty(Q)){
        cout<<"Empty queue"<<endl;
        return 0;
    }else{
        return Q->Array[Q->Frout];
    }
}
void Dequeue( Queue Q ){
    if(IsEmpty(Q)){
        cout<<"Empty queue"<<endl;
    }else{
        Q->Size--;
        Q->Frout = Succ(Q->Frout,Q);
    }
}
ElementType FrontAndDequeue( Queue Q ){
    ElementType value;
    if(!IsEmpty(Q)){
        value = Front(Q);
        Dequeue(Q);
        return value;
    }
    cout<<"Empty queue"<<endl;
    return 0;
}