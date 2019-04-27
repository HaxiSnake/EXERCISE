class Solution {
private:
    vector<int> parent;
    vector<int> rank;
public:
    int regionsBySlashes(vector<string>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].length();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                  parent.push_back(i*n*4+j*4+k);
                  rank.push_back(0);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i){
                    _union(i*n*4+j*4+0, (i-1)*n*4+j*4+2);
                }
                if(j){
                    _union(i*n*4+j*4+3, i*n*4+(j-1)*4+1);
                }
                if(grid[i][j]!='/'){
                    _union(i*n*4+j*4+0, i*n*4+j*4+1);
                    _union(i*n*4+j*4+2, i*n*4+j*4+3);
                }
                if(grid[i][j]!='\\'){
                    _union(i*n*4+j*4+0, i*n*4+j*4+3);
                    _union(i*n*4+j*4+1, i*n*4+j*4+2);
                }
            }
        }
        set<int> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    res.insert(_find(i*n*4+j*4+k));
                }
            }
        }
        return res.size();
        
        
    }
    int _find(int x){
        return parent[x]==x?x:(parent[x]=_find(parent[x]));
    }
    void _union(int x,int y){
        int px = _find(x);
        int py = _find(y);
        if(rank[px]<rank[py]){
            parent[px]=py;
        }else{
            parent[py]=px;
            if(rank[px]==rank[py]){
                rank[px]+=1;
            }
        }
    }
};