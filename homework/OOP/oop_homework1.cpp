#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Sales_data{
    string bookno;
    unsigned int unit_sold=0;
    double income=0.0;
};
#define SIZE 1000 //最大存储记录条数
bool Read(istream& is, Sales_data* pData);
void Print(ostream& os,Sales_data* pData);
int logs(Sales_data* pRec, Sales_data* pLogs, int nSize);
bool isLegal(Sales_data* pRec);     
void makeEmpty(Sales_data* pLogs, int nSize);
int main(int argc, char const *argv[])
{
    Sales_data* pLog;
    //pLog=(Sales_data*)malloc(SIZE*sizeof(struct Sales_data));
    //此处要使用new方法来分配空间，不然无法调用string类型的构造方法
    pLog=new Sales_data[SIZE];
    int value;
    if(NULL==pLog){
        cout<<"MEMORY ACCESS FAILED!"<<endl;
        return -1;
    }  
    makeEmpty(pLog,SIZE);
    struct Sales_data adata;
    //从控制台读取记录
    cout<<"Please input bookNo, count, price"<<endl;
    while(Read(cin,&adata)){
        value = logs(&adata,pLog,SIZE);
        if(value<0)
            cout<<"ERROR INPUT!"<<endl;
        else if(value>=SIZE){   
            cout<<"NO ENOUGH SPACE"<<endl;
            break;
        }
    }
    cout<<"Read log over."<<endl;
    //输出记录到数据文件及终端
    ofstream os("log.txt");
    for(int i=0;i<SIZE;i++){
        if(pLog[i].bookno.empty())
            break;
        Print(os,&pLog[i]);
        Print(cout,&pLog[i]);
    }
    getchar();
    getchar();
    return 0;
}

bool Read(istream& is, Sales_data* pData){
    if(NULL==pData)
        return false;
    if(is>>pData->bookno>>pData->unit_sold>>pData->income){
        pData->income=pData->unit_sold*pData->income;
        return true;
    }else
        return false;
}
void Print(ostream& os,Sales_data* pData){
    if(NULL==pData)
        return;
    os<<pData->bookno<<'\t'<<pData->unit_sold<<'\t'<<pData->income<<endl;
}

int logs(Sales_data* pRec, Sales_data* pLogs, int nSize){
    if(!isLegal(pRec)){
        return -1;
    }else{
        for(int i=0;i<nSize;i++){
            if(!pLogs[i].bookno.empty()&&pLogs[i].bookno==pRec->bookno){
                pLogs[i].unit_sold+=pRec->unit_sold;
                pLogs[i].income+=pRec->income;
                return i+1;
            }else if(pLogs[i].bookno.empty()){
                pLogs[i].bookno=pRec->bookno;
                pLogs[i].unit_sold=pRec->unit_sold;
                pLogs[i].income=pRec->income;
                return i+1;
            }
        }
    }
}
bool isLegal(Sales_data* pRec){
    if(NULL==pRec){
        return false;
    }else if(pRec->unit_sold<=0 || pRec->income<=0){
        return false;
    }else{
        return true;
    }
}
void makeEmpty(Sales_data* pLogs, int nSize){
    for(int i=0;i<nSize;i++){
        pLogs[i].bookno=string();
    }
}