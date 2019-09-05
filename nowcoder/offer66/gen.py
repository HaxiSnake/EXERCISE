import os
os.chdir(os.path.dirname(__file__))
title="31.数组中出现次数超过一半的数字"
content="数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0."
isstar=True
code="""
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        if(len<=0) return 0;
        if(len==1) return numbers[0];
        int value,count;
        value=numbers[0];
        count=1;
        for(int i=0; i<len; i++){
            int num = numbers[i];
            if(count==0){
                value = num;
                count = 1;
            }else{
                if(value==num){
                    count++;
                }else{
                    count--;
                }
            }
        }
        count=0;
        for(int i=0 ; i<len; i++){
            if(numbers[i]==value){
                count++;
            }
        }
        return count>len/2?value:0;        
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



