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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> lvec(0),rvec(0),result(0);
        if(NULL==root){
            return result;
        }else{
            lvec=inorderTraversal(root->left);
            lvec.push_back(root->val);
            rvec=inorderTraversal(root->right);
            result.insert(result.end(),lvec.begin(),lvec.end());
            result.insert(result.end(),rvec.begin(),rvec.end());
            
        }
        return result;
    }
};