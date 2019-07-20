import os
os.chdir(os.path.dirname(__file__))
title="20.字符流中第一个不重复的字符"
content="请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符'go'时，第一个只出现一次的字符是'g'。当从该字符流中读出前六个字符'google'时，第一个只出现一次的字符是'l'。"
isstar=True
code="""
class Solution
{
private:
    queue<char> data;
    int cnt[128];
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         cnt[ch-'\0']++;
        if(cnt[ch-'\0']==1){
            data.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty() && cnt[data.front()-'\0']>1) data.pop();
        if(data.empty()) return '#';
        else return data.front();
    }
    Solution(){
        memset(cnt,0,sizeof(cnt));
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



