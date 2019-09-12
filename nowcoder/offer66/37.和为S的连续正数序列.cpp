
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<int> item;
        vector<vector<int>> res;
        int plow,phigh;
        plow=1;
        phigh=2;
        while(plow<phigh){
            int num = (plow+phigh)*(phigh-plow+1)/2;
            if(num==sum){
                item.clear();
                for(int i=plow;i<=phigh;i++){
                    item.push_back(i);
                }
                res.push_back(item);
                plow++;
            }
            else if(num<sum){
                phigh++;
            }
            else if(num>sum){
                plow++;
            }
        }
        return res;
    }
};
