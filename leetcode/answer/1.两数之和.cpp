/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素

思路：建立哈希表并查找另一个元素，时间复杂度O(n)

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];
            if(map.count(complement)){
                // vector<int> result(map[complement],i);
                vector<int> result;
                result.push_back(map[complement]);
                result.push_back(i);
                return result;
            }
            map[nums[i]]=i;
        }
        
    }
}; 