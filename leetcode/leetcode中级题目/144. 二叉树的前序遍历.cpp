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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        if(!root){
            return {};
        }
        nodes.push(root);
        vector<int> res;
        while(!nodes.empty()){
            TreeNode* p=nodes.top();
            nodes.pop();
            res.push_back(p->val);
            if(p->right){
                nodes.push(p->right);
            }
            if(p->left){
                nodes.push(p->left);
            }
        }
        return res;
    }
};