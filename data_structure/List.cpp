#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
List MakeEmpty(){
    List L;
    L->Next = NULL;
    return L;
}

int IsEmpty( List L ){
    return L->Next == NULL;
}

int IsLast( Position P, List L){
    return P->Next == NULL;
}

Position Find( ElementType X, List L ){
    Position P;
    P = L->Next;
    while( P!= NULL && P->Element!=X){
        P=P->Next;
    }
    return P;
}

void Delete( ElementType X, List L ){
    Position P, tempNode;
    P=FindPrevious(X,L);
    if(!IsLast(P,L)){
        tempNode = P->Next;
        P->Next = tempNode->Next;
        free(tempNode);
    }
}

Position FindPrevious( ElementType X, List L){
    Position P = L;
    while( P->Next != NULL && P->Next->Element!=X )
        P=P->Next;
    return P;
}
void Insert( ElementType X, List L, Position P){
    Position tempNode;
    tempNode = (Position)malloc(sizeof(Node));
    if (tempNode == NULL){
        cout<<"Out of Memory!"<<endl;
    }
    tempNode->Element=X;
    tempNode->Next=P->Next;
    P->Next=tempNode;
}