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
    vector<double> sum;
    vector<int> count;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        bfs(root,0);
        vector<double> res;
        for(int i=0;i<sum.size();i++){
            res.push_back(sum[i]/count[i]);
        }
        return res;
    }
    void bfs(TreeNode* root, int level){
        if(root==NULL) return;
        if(level==count.size()){
            count.push_back(1);
            sum.push_back(root->val);
        }else{
            count[level]+=1;
            sum[level]+=root->val;
        }
        if(root->right){
            bfs(root->right,level+1);
        }
        if(root->left){
            bfs(root->left,level+1);
        }
    }
};