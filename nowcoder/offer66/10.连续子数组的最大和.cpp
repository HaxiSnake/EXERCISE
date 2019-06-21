
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int i = 0,maxsub=array[0];
         
        for(i=0;i<array.size();i++){
            if(maxsub<array[i]) maxsub=array[i];
            if(array[i]>=0) break;
        }
        if(i==array.size()) return maxsub;
        int sum=0;
        for(;i<array.size();i++){
            sum+=array[i];
            if(sum>maxsub){
                maxsub=sum;
            }
            if(sum<=0){
                sum=0;
            }
        }
        return maxsub;
    }
};
