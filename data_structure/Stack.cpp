#include "Stack.h"
#include <stdlib.h>
#include<iostream>
using namespace std;
int IsEmpty( Stack S ){
    return S->next == NULL;
}

Stack CreateStack( void ){
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    if ( S==NULL ){
        cout<<"Out of space!"<<endl;
    }
    S->next = NULL;
    MakeEmpty( S );
    return S;
}

void MakeEmpty( Stack S ){
    if( S == NULL ){
        cout<<"Must use CreateStack first!"<<endl;
    }else{
        while(!IsEmpty( S )){
            Pop(S);
        }
    }
}

void DisposeStack( Stack S ){
    MakeEmpty( S );
}

void Push( ElementType X,Stack S ){
    Stack tempStack;
    tempStack = (Stack) malloc( sizeof( struct Node));
    if (tempStack==NULL)
        cout<<"Out of Space"<<endl;
    else{
        tempStack->Element = X;
        tempStack->next = S->next;
        S->next = tempStack;
    }
}

ElementType Top( Stack S ){
    if(!IsEmpty(S))
        return S->next->Element;
    else{
        cout<<"Empty Stack"<<endl;
        return 0;
    }  
}

void Pop( Stack S ){
    Stack FirstCell;
    if(IsEmpty(S)){
        cout<<"Empty Stack"<<endl;
    }else{
        FirstCell = S->next;
        S->next=S->next->next;
        free(FirstCell);
    }
}
