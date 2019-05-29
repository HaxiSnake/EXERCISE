
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot==NULL) return true;
        if(pRoot->left==NULL && pRoot->right==NULL) return true;
        if(IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right)){
            int left=_depth(pRoot->left);
            int right=_depth(pRoot->right);
            if(abs(left-right)<=1) return true;
            else return false;
        }else{
            return false;
        }
    }
    int _depth(TreeNode* pRoot){
        if(pRoot==NULL){
            return 0;
        }
        if(pRoot->left==NULL && pRoot->right==NULL){
            return 0;
        }
        return max(_depth(pRoot->left),_depth(pRoot->right))+1;
    }
};
