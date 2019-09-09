import os
os.chdir(os.path.dirname(__file__))
title="33.剪绳子"
content="给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为k[0],k[1],...,k[m]。请问k[0]xk[1]x...xk[m]可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。 "
isstar=False
code="""
class Solution {
public:
    int cutRope(int number) {
        int n = number;
        vector<int> res(n+1);
        if(n<2 || n>60) return 0;
        res[1]=1;
        if(n==2) return 1;
        if(n==3) return 2;
        res[2]=2;
        res[3]=3;
        for(int i=4;i<=n;i++){
            res[i]=max(res[i-1],i);
            for(int j=1;j<n;j++){
                int multi = res[j]*res[i-j];
                res[i]=res[i]>multi?res[i]:multi;
            }
        }
        return res[n];
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



