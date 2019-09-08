
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
