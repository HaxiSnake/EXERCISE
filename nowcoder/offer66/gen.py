import os
os.chdir(os.path.dirname(__file__))
title="10.连续子数组的最大和"
content="HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学.今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决.但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止).给一个数组,返回它的最大连续子序列的和,你会不会被他忽悠住?(子向量的长度至少是1)"
isstar=False
code="""
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int i = 0,maxsub=array[0];
         
        for(i=0;i<array.size();i++){
            if(maxsub<array[i]) maxsub=array[i];
            if(array[i]>=0) break;
        }
        if(i==array.size()) return maxsub;
        int sum=0;
        for(;i<array.size();i++){
            sum+=array[i];
            if(sum>maxsub){
                maxsub=sum;
            }
            if(sum<=0){
                sum=0;
            }
        }
        return maxsub;
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



