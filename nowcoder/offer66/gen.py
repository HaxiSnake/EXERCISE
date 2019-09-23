import os
os.chdir(os.path.dirname(__file__))
title="44.二维数组中的查找"
content='在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。'
isstar=True
code="""
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()<=0 || array[0].size()<=0) return false;
        int col=array[0].size()-1;
        int row=0;
        while(col>=0 && row<=array.size()-1){
            if(array[row][col]==target) return true;
            else{
                if(array[row][col]<target){
                    row++;
                }else{
                    col--;
                }
            }
        }
        return false;
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



