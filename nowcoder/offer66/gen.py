import os
os.chdir(os.path.dirname(__file__))
title="26.二叉树的下一个结点"
content="给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。"
isstar=False
code="""
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
"""
md_list="* [{0}](#{0}) [解答](./{0}.cpp)".format(title)
essay="## {0}\n\n{1}\n".format(title,content)
if(isstar):
    md_list+=" &star;"

print(md_list)
print(essay)

with open("{0}.cpp".format(title),'w') as out:
    out.writelines(code)
out.close()



