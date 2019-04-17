class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size();
        int n=nums[0].size();
        if(m*n != r*c){
            return nums;
        }
        vector<vector<int> > res;
        vector<int> row(c);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=i*n+j+1;
                if(count%c==0){
                    row[c-1]=nums[i][j];
                    res.push_back(row);
                   
                }else{
                    row[count%c-1]=nums[i][j];
                }
            }
        }
        return res;
    }
};