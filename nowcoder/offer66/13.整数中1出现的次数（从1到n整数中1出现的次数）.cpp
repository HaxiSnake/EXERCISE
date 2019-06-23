
class Solution {
public:
 int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        int a=0,b=0;
        for(long long m=1;m<=n;m*=10){
            a = n/m;
            b = n%m;
            cnt+=(a+8)/10*m + (a%10==1)*(b+1);
        }
        return cnt;
    }
};
