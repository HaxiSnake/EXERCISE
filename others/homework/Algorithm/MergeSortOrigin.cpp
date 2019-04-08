#include<iostream>
#include<stdlib.h>

using namespace std;

#define SEED 123
#define LENGTH 13
#define EVERY_LINE 10 
#define NUMRANGE 1000
typedef int ElementType;

void output(ostream& fo,ElementType data[],int length );
void Merge(ElementType* E, ElementType* B, int s, int m, int t);
void Msort(ElementType* E,ElementType* B,int s,int t);
void Msort1(ElementType* E,ElementType* B,int length);//Msort without recursive
void MergeNoWB(ElementType* E, ElementType* B, int s, int m, int t);
void Msort2(ElementType* E,ElementType* B,int length);
int main(){
    ElementType data[LENGTH];
    ElementType B[LENGTH];
    int i;
    srand(SEED);
    for(i=0;i<LENGTH;i++){
        data[i]=rand()%NUMRANGE;
    };
    output(cout,data,LENGTH);
    cout<<endl;
    Msort2(data,B,LENGTH-1);
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

void Merge(ElementType* E, ElementType* B, int s, int m, int t){
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
    for(p=s;p<=t;p++)
        E[p]=B[p];
}

void Msort(ElementType* E,ElementType* B,int s,int t){
    int m;
    if(s<t){
        m=(s+t)/2;
        Msort(E,B,s,m);
        Msort(E,B,m+1,t);
        Merge(E,B,s,m,t);
    }
}
//Msort without recursive
void Msort1(ElementType* E,ElementType* B,int length){
    int step,i;
    for(step=2;(step>>1)-1<=length;step=step<<1){
        //cout<<step<<endl;
        for(i=0;i+step-1<=length;i+=step){
            cout<<endl<<"i:"<<i<<endl;
            Merge(E,B,i,i-1+(step>>1),i-1+step);
            output(cout,E,length+1);
        }
        if(i+(step>>1)-1<=length){
            cout<<"merge tail  "<<i<<endl;
            Merge(E,B,i,i+(step>>1)-1,length);
        }
        cout<<"step:"<<step<<endl;
        output(cout,E,length+1);
    }
}
//Msort without recursive and write back
void Msort2(ElementType* E,ElementType* B,int length){
    int step,i;
    ElementType* tempE;
    ElementType* tempB;
    ElementType* temp;
    int counter=0;
    tempE=E;
    tempB=B;
    for(step=2;(step>>1)-1<=length;step=step<<1,counter+=1){
        //cout<<step<<endl;
        for(i=0;i+step-1<=length;i+=step){
            //cout<<endl<<"i:"<<i<<endl;
            MergeNoWB(tempE,tempB,i,i-1+(step>>1),i-1+step);
            //output(cout,E,length+1);
        }
        if(i+(step>>1)-1<=length){
            MergeNoWB(tempE,tempB,i,i+(step>>1)-1,length);
        }
        //cout<<"step:"<<step<<endl;
        temp=tempE;
        tempE=tempB;
        tempB=temp;
        //output(cout,tempE,length+1);
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