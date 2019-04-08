/*
最大子串和问题
本算法的时间复杂度为O(n)
*/

#include<iostream>
#include<stdlib.h>  
#include<vector>

using namespace std;

int main(void){

    vector<int> array{38,-62,47,-33,28,13,-18,-46,8,21,12,-53,25};
    vector<int>::iterator start=array.begin();
    vector<int>::iterator end=array.end();
    vector<int>::iterator it;

    int max_sum=0;
    int this_sum=0;
    for(it=start;it!=end;it++){
        this_sum=this_sum+*it;
        if(this_sum<0){
            this_sum=0;
        }
        if(this_sum>max_sum){
            max_sum=this_sum;
        }
    }
    cout<<"max sub sum is:"<<max_sum<<endl;
    system("pause");
    return 0;
}