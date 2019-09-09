
class Solution {
public:
    int cutRope(int number) {
        int n = number;
        vector<int> res(n+1);
        if(n<2 || n>60) return 0;
        res[1]=1;
        if(n==2) return 1;
        if(n==3) return 2;
        res[2]=2;
        res[3]=3;
        for(int i=4;i<=n;i++){
            res[i]=max(res[i-1],i);
            for(int j=1;j<n;j++){
                int multi = res[j]*res[i-j];
                res[i]=res[i]>multi?res[i]:multi;
            }
        }
        return res[n];
    }
};
