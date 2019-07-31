import os
os.chdir(os.path.dirname(__file__))
title="22.把二叉树打印成多行"
content="从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。 "
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



