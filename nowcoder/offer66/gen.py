import os
os.chdir(os.path.dirname(__file__))
title="37.和为S的连续正数序列"
content="小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck! "
isstar=True
code="""
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<int> item;
        vector<vector<int>> res;
        int plow,phigh;
        plow=1;
        phigh=2;
        while(plow<phigh){
            int num = (plow+phigh)*(phigh-plow+1)/2;
            if(num==sum){
                item.clear();
                for(int i=plow;i<=phigh;i++){
                    item.push_back(i);
                }
                res.push_back(item);
                plow++;
            }
            else if(num<sum){
                phigh++;
            }
            else if(num>sum){
                plow++;
            }
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



