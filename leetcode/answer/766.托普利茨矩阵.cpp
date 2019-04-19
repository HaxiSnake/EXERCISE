class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<int> onerow;
        for(auto cur:matrix){
            if(onerow.size()<=0){
                onerow.clear();
                for(auto num:cur){
                    onerow.push_back(num);
                }
            }else{
                for(int j=cur.size()-1;j>=1;j--){
                    if(onerow[j-1]!=cur[j]){
                        return false;
                    }else{
                        onerow[j]=cur[j];
                    }
                }
                onerow[0]=cur[0];
            }
        }
        return true;
    }
    
};