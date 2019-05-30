
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> res(number+1,0);
        res[1]=1;
        for(int i=2;i<=number;i++){
            res[i]=res[i-1]*2;
        }
        return res[number];
    }
     
};
