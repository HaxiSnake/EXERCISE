import os
os.chdir(os.path.dirname(__file__))
title="4.二叉树的镜像"
content="操作给定的二叉树，将其变换为源二叉树的镜像。"
isstar=False
code="""
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        if(pRoot->left==NULL && pRoot->right==NULL) return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode* tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        return;
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



