
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
