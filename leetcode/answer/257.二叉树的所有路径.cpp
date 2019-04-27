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
private:
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
        vector<string> left;
        vector<string> right;
        vector<string> res;
        left=binaryTreePaths(root->left);
        right=binaryTreePaths(root->right);
        if(left.size()==0 && right.size()==0){
            return {to_string(root->val)};
        }else{
            for(auto item:left){
                res.push_back(to_string(root->val)+"->"+item);
            }
            for(auto item:right){
                res.push_back(to_string(root->val)+"->"+item);
            }
            return res;
        }
    }
};