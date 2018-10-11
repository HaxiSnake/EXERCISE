#include<stdlib.h>
// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int m = __INT_MAX__;
        TreeNode* tmp;
        if(root==NULL){
            return __INT_MAX__;
        }else {
            if(root->left!=NULL){
                m = min( getMinimumDifference(root->left) , m );
                tmp = findMax(root->left);
                m = min( abs(tmp->val-root->val),m);
            };
            if(root->right!=NULL){
                m = min( getMinimumDifference(root->right) , m );
                tmp = findMin(root->right);
                m = min( abs(tmp->val-root->val),m);
            };
            return m;
        };
    };
    TreeNode* findMin(TreeNode* p){
        if(p!=NULL){
            while(p->left!=NULL)
                p=p->left;
        }
        return p;
    }
    TreeNode* findMax(TreeNode* p){
        if(p!=NULL){
            while(p->right!=NULL)
                p=p->right;
        }
        return p;
    }
};