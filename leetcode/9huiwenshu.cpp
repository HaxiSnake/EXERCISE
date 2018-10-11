#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10 ==0 && x!=0))
            return false;
        int reverseNumber=0;
        while ( x > reverseNumber){
            reverseNumber = reverseNumber*10 + x%10;
            x= x/10;
        }
        return x==reverseNumber || x==reverseNumber/10;
    }
};
int main(int argc,char *args[]){
    int i;
    bool result;
    i=9999;
    Solution sol ;
    result = sol.isPalindrome(i);
    cout << result << endl;
    getchar();
    return 0;
}
