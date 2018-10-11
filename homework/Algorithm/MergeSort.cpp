#include<iostream>
#include<stdlib.h>

using namespace std;

#define SEED 123
#define LENGTH 13
#define EVERY_LINE 10 
#define NUMRANGE 1000
typedef int ElementType;

void output(ostream& fo,ElementType data[],int length );
void MergeNoWB(ElementType* E, ElementType* B, int s, int m, int t);
void Msort(ElementType* E,ElementType* B,int length);
int main(){
    ElementType data[LENGTH];
    ElementType B[LENGTH];
    int i;
    srand(SEED);
    for(i=0;i<LENGTH;i++){
        data[i]=rand()%NUMRANGE;
    };
    cout<<"input data:"<<endl;
    output(cout,data,LENGTH);
    cout<<endl;
    Msort(data,B,LENGTH-1);
    cout<<"sorted data:"<<endl;
    output(cout,data,LENGTH);
    getchar();
    return 0;
}

void output(ostream& fo,ElementType data[],int length ){
    int counter=0, i=0;
    for( i=0; i<length; i++ ){
        fo<<data[i]<<'\t';
        ++counter;
        if(counter==EVERY_LINE){
            fo<<endl;
            counter=0;
        }
    }
    fo<<endl;
}

//Msort without recursive and write back
void Msort(ElementType* E,ElementType* B,int length){
    int step,i;
    ElementType* tempE;
    ElementType* tempB;
    ElementType* temp;
    int counter=0;
    tempE=E;
    tempB=B;
    for(step=2;(step>>1)-1<=length;step=step<<1,counter+=1){
        for(i=0;i+step-1<=length;i+=step){
            MergeNoWB(tempE,tempB,i,i-1+(step>>1),i-1+step);
        }
        if(i+(step>>1)-1<=length){
            MergeNoWB(tempE,tempB,i,i+(step>>1)-1,length);
        }
        temp=tempE;
        tempE=tempB;
        tempB=temp;
    }
    if(counter%2 == 1){
        for(int j=0;j<=length;j++)
            E[j]=B[j];
    }
}
void MergeNoWB(ElementType* E, ElementType* B, int s, int m, int t){
    int k,p,j;
    for(k=s,p=s,j=m+1;p<=m && j<=t;++k){
        if(E[p]<E[j]) 
            B[k]=E[p++];
        else
            B[k]=E[j++];
    }
    if(p<=m){
        for(;p<=m;p++){
            B[k++]=E[p];
        }
    }
    if(j<=t){
        for(;j<=t;j++){
            B[k++]=E[j];
        }
    }
}