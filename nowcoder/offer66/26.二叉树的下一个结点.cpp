
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return NULL;
        if(pNode->right==NULL){
            TreeLinkNode* cur=pNode;
            while(cur->next!=NULL){
                if(cur->next->left==cur) return cur->next;
                else cur=cur->next;
            }
            return cur->next;
        }else{
            TreeLinkNode* cur=pNode->right;
            while(cur->left!=NULL){
                cur=cur->left;
            }
            return cur;
        }
    }
};
