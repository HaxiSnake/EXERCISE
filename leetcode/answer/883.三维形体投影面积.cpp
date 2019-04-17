class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int xy_area=0;
        vector<int> xz_area(grid[0].size(),0);
        vector<int> yz_area(grid.size(),0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    xy_area++;
                    if(grid[i][j]>xz_area[j]){
                        xz_area[j]=grid[i][j];
                    }
                    if(grid[i][j]>yz_area[i]){
                        yz_area[i]=grid[i][j];
                    }
                }
            }
        }
        int res=0;
        for(auto x:xz_area){
            res+=x;
        }
        for(auto y:yz_area){
            res+=y;
        }
        return res+xy_area;
        
    }
};