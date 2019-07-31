
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
    queue<TreeNode*> lay_nodes;
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot==NULL) return res;
            lay_nodes.push(pRoot);
            lay_nodes.push(NULL);
            while(lay_nodes.size()){
                vector<int> one_layer;
                while( lay_nodes.size()>0 && lay_nodes.front()!=NULL){
                    TreeNode* node;
                    node=lay_nodes.front();
                    lay_nodes.pop();
                    one_layer.push_back(node->val);
                    if(node->left!=NULL){
                        lay_nodes.push(node->left);
                    }
                    if(node->right!=NULL){
                        lay_nodes.push(node->right);
                    }
                }
                res.push_back(one_layer);
                lay_nodes.pop();
                if(lay_nodes.size()<=0) break;
                lay_nodes.push(NULL);
                 
            }
            return res;
        }
     
};
