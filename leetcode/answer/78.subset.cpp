/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> total;
        int subcount=pow(2,nums.size());
        for(int i=0;i<subcount;i++){
            for(int k=0;k<nums.size();k++){
                if((i>>k)&1){
                    subset.push_back(nums[k]);
                }
            }
            total.push_back(subset);
            subset.clear();
        }
        return total;
    }
};