class Solution {
public:
    string intToRoman(int num) {
        string res="";
        vector<int> val={1000,500,100,50,10,5,1};
        vector<string> key={"M","D","C","L","X","V","I"};
        int i=0;
        while(num>=1){
            for(i=0;i<val.size();i++){
                if(num>=val[i]) break;
            }
            int tmp=num;
            while(tmp>=10){
                tmp/=10;
            }
            if(tmp==9){
                res=res+key[i+1]+key[i-1];
                num-=(val[i+1]*9);
            }else if(tmp==4){
                res=res+key[i]+key[i-1];
                num-=(val[i]*4);
            }else{
                res+=key[i];
                num-=val[i];
            }
            
        }
        return res;
    }
};