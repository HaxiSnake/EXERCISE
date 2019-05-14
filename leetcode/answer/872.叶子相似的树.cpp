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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> left=getLeaves(root1);
        vector<int> right=getLeaves(root2);
        if(left.size()!=right.size()){
            return false;
        }else{
            for(int i=0;i<left.size();i++){
                if(left[i]!=right[i]){
                    return false;
                }
            }
            return true;
        }
    }
    vector<int> getLeaves(TreeNode* root){
        vector<int> res;
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL){
            return {root->val};
        }
        
        vector<int> left=getLeaves(root->left);
        vector<int> right=getLeaves(root->right);
        left.insert(left.begin(),right.begin(),right.end());
        return left;
    }
};