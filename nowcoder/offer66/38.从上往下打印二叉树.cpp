
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if( root==NULL ) return res;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.front()->val);
            if(q.front()->left!=NULL){
                 q.push(q.front()->left);   
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return res;
    }
};
