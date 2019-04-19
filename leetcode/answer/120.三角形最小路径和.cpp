class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        vector<int> res(triangle.size(),INT_MAX);
        res[0]=triangle[0][0];
        for(int i=1;i<triangle.size();i++){
            res[i]=res[i-1]+triangle[i][i];
            for(int j=i-1;j>=1;j--){
                res[j]=triangle[i][j]+(res[j-1]<res[j]?res[j-1]:res[j]);
            }
            res[0]+=triangle[i][0];
        }
        int rtn=INT_MAX;
        for(auto num:res){
            if(rtn>num){
                rtn=num;
            }
        }
        return rtn;
    }
};