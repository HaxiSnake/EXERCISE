
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int k=0;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1){
                int j=i;
                int tmp=array[j];
                while(j>k){
                    array[j]=array[j-1];
                    j--;
                }
                array[k++]=tmp;
            }
        }
        return;
    }
 
};
