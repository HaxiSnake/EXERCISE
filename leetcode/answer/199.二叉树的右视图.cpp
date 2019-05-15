/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        if(root->left==NULL && root->right==NULL) return {root->val};
        vector<int> lv= rightSideView(root->left);
        vector<int> rv= rightSideView(root->right);
        if(lv.size()<=rv.size()){
            rv.insert(rv.begin(),root->val);
            return rv;
        }else{
            rv.insert(rv.end(),lv.begin()+rv.size(),lv.end());
            rv.insert(rv.begin(),root->val);
            return rv;
        }
    }
};