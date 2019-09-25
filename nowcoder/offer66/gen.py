import os
os.chdir(os.path.dirname(__file__))
title="46.二叉搜索树的后序遍历序列"
content='输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。'
isstar=True
code="""
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()<=0) return false;
           return _verify(0,sequence.size()-1,sequence);
    }
    bool _verify(int start,int end,vector<int>& sequence){
        if(start>end) return true;
        int i=end-1;
        for(i=end-1;i>=start;i--){
            if(sequence[i]<sequence[end]) break;
        }
        for(int j=start;j<=i;j++){
            if(sequence[j]>sequence[end]) return false;
        }
        return _verify(start,i,sequence) && _verify(i+1,end-1,sequence);
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



