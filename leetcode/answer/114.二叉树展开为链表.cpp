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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->left==NULL) {
            flatten(root->right);
        }else{
            flatten(root->left);
            TreeNode* node=findRightTail(root->left);
            flatten(root->right);
            node->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        
    }
    TreeNode* findRightTail(TreeNode* node){
        while(node->right!=NULL){
            node=node->right;
        }
        return node;
    }
};