import os
os.chdir(os.path.dirname(__file__))
title="35.把字符串转换成整数"
content="将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。"
isstar=True
code="""
class Solution {
public:
    int StrToInt(string str) {
        if(str.length()==0) return 0;
        //if(str.length()>10) return 0;
        int flag=1;
        int i=0;
        if(str[0]=='+'){
            flag=1;
            i = 1;
        }else if(str[0]=='-'){
            flag=-1;
            i = 1;
        }
        int res=0;
        for(;i<str.length();i++){
            if(str[i]<'0' || str[i]>'9') return 0;
            int delta = INT_MAX - res*10;
            int bit = str[i]-'0';
             
            if(flag==1){
                if(delta<bit) return 0;
            }else{
                if(delta!=INT_MAX){
                    if(delta+1<bit) return 0;
                    if(delta+1==bit) return INT_MIN;
                }
            }
            res = res*10 + bit;
        }
        return flag*res;
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



