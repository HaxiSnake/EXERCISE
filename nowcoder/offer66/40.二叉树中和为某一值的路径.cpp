
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
    vector<vector<int>> res;
    static bool cmp(vector<int> &a, vector<int> &b){
        return a.size()>b.size();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> path;
        Search(root, path, expectNumber);
        sort(res.begin(),res.end(),cmp);
        return res;
    }
     
    void Search(TreeNode* root, vector<int> path, int number){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(root->val==number){
                path.push_back(root->val);
                res.push_back(path);
            }else{
                return;
            }
        }else{
            path.push_back(root->val);
            number=number-root->val;
            Search(root->left,path,number);
            Search(root->right,path,number);
        }
    }
};
