class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        vector<vector<int>> res(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && j==0){
                    res[i][j]=grid[0][0];
                }else if(i==0){
                    res[i][j]=res[i][j-1]+grid[i][j];
                }else if(j==0){
                    res[i][j]=res[i-1][j]+grid[i][j];
                }else{
                    res[i][j]=min(res[i-1][j],res[i][j-1])+grid[i][j];
                }
            }
        }
        return res[grid.size()-1][grid[0].size()-1];
    }
};