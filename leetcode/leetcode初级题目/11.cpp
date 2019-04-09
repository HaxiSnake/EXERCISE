#include<stdio.h>
#include<vector>
#include<iostream>
#include <algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i,j;
        i=0;
        j=height.size()-1;
        while(i<j){
            result=max(calArea(height.at(i),height.at(j),j-i),result);
            if(height.at(i)<height.at(j)){
                i++;
            }else{
                j--;
            }
        }
        return result;
    }
private:
    int calArea(int x,int y,int n){
        return x>y?y*n:x*n;
    }
};
int main(int argc,char *args[]){
    int result;
    std::vector<int> vec1({1,8,6,2,5,4,8,3,7});
    vector<int>::iterator it;
    // for (it = vec1.begin();it!=vec1.end();it++)
    //     cout <<*it<<endl;
    Solution sol;
    result = sol.maxArea(vec1);
    cout << result << endl;
    getchar();
    return 0;
}
