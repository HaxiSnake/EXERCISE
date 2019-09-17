import os
os.chdir(os.path.dirname(__file__))
title="41.调整数组顺序使奇数位于偶数前面"
content='输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。'
isstar=True
code="""
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int k=0;
        for(int i=0;i<array.size();i++){
            if(array[i]%2==1){
                int j=i;
                int tmp=array[j];
                while(j>k){
                    array[j]=array[j-1];
                    j--;
                }
                array[k++]=tmp;
            }
        }
        return;
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



