
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()<=0 || array[0].size()<=0) return false;
        int col=array[0].size()-1;
        int row=0;
        while(col>=0 && row<=array.size()-1){
            if(array[row][col]==target) return true;
            else{
                if(array[row][col]<target){
                    row++;
                }else{
                    col--;
                }
            }
        }
        return false;
    }
    
};
