class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,k=0;
        for(i=0;i<nums1.size();i++){
            for(k=0;k<nums2.size();k++){
                if(nums2[k]==nums1[i]) break;
            }
            for(j=k+1;j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    nums1[i]=nums2[j];
                    break;
                }
            }
            if(j==nums2.size()){
                nums1[i]=-1;
            }
        }
        return nums1;
    }
};