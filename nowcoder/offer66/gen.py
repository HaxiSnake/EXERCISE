import os
os.chdir(os.path.dirname(__file__))
title="24.数字在排序数组中出现的次数"
content="统计一个数字在排序数组中出现的次数。"
isstar=False
code="""
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()<=0) return 0;
        int left=0,right=data.size();
        int mid = (left + right)/2;
        bool dec;
        if(data[left] <= data[right]){
            dec=false;
        }else{
            dec=true;
        }
        while(left<=right && data[mid]!=k){
            if( data[mid] > k ){
                if(dec){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else if( data[mid] < k ){
                if(dec){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            mid = ( left + right )/2;
        }
        if(data[mid]!=k || left>right) return 0;
        int l_k=mid, r_k=mid;
        while( l_k>=0 && data[l_k] == k){
            l_k--;
        }
        while( r_k<data.size() && data[r_k] == k){
            r_k++;
        }
        return r_k-l_k-1;
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



