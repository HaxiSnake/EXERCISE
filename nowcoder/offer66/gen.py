import os
os.chdir(os.path.dirname(__file__))
title="32.把数组排成最小的数"
content="输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。"
isstar=True
code="""
class Solution {
public:
    static bool cmp(int a, int b){
        string A="";
        string B="";
        A+=to_string(a);
        A+=to_string(b);
        B+=to_string(b);
        B+=to_string(a);
        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        int len=numbers.size();
        if(len<=0) return "";
        sort(numbers.begin(),numbers.end(),cmp);
        string ans="";
        for(int i=0;i<len;i++){
            ans+=to_string(numbers[i]);
        }
        return ans;
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



