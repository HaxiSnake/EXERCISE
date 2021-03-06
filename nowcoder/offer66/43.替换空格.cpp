
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count=0;
        int i;
        for(i=0;i<length && str[i]!=' ';i++){
            if(str[i]==' ') count++;
        }
        if(count*2+i>length) return;
        for(int j=i;j>=0;j--){
            if(str[j]!=' '){
                str[j+2*count]=str[j];
            }else{
                count--;
                str[j+2*count]='%';
                str[j+2*count+1]='2';
                str[j+2*count+2]='0';
            }
        }
        return;
    }
};
