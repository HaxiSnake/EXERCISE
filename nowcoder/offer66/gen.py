import os
os.chdir(os.path.dirname(__file__))
title="12.跳台阶"
content="一只青蛙一次可以跳上1级台阶，也可以跳上2级.求该青蛙跳上一个n级的台阶总共有多少种跳法(先后次序不同算不同的结果). "
isstar=False
code="""
class Solution {
public:
    int jumpFloor(int number) {
        if(number<1) return 0;
        int a=1,b=2;
        while(--number){
            b=a+b;
            a=b-a;
        }
        return a;
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



