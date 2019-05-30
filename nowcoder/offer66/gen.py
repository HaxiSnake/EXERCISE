import os
os.chdir(os.path.dirname(__file__))
title="6.构建乘积数组"
content="给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。"
isstar=False
code="""
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(),1);
        vector<int> C(A.size(),1);
        B[0]=1;
        C[A.size()-1]=1;
        for(int i=1;i<A.size();i++){
            B[i]=B[i-1]*A[i-1];
            C[A.size()-i-1]=C[A.size()-i]*A[A.size()-i];
        }
        for(int i=0;i<A.size();i++){
            B[i]=B[i]*C[i];
        }
        return B;
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



