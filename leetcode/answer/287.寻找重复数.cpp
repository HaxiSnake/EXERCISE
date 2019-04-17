class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            int count=0;
            for(auto num:nums){
                if(num<=mid){
                    count++;
                }
            }
            if(count<=mid){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};