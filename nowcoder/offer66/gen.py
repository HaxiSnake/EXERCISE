import os
os.chdir(os.path.dirname(__file__))
title="8.用两个栈实现队列"
content="用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。"
isstar=False
code="""
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }
 
    int pop() {
        if(!stack2.empty()){
            int res=stack2.top();
            stack2.pop();
            return res;
        }else{
            if(!stack1.empty()){
                while(!stack1.empty()){
                    int res=stack1.top();
                    stack2.push(res);
                    stack1.pop();
                }
                int res=stack2.top();
                stack2.pop();
                return res;
            }else{
                return -1;
            }
        }
    }
 
private:
    stack<int> stack1;
    stack<int> stack2;
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



