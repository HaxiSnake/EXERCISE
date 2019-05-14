class Solution {
public:
    int binaryGap(int N) {
        int fir_pos=-1;
        int max_len=0;
        int pos=-1;
        while(N!=0){
            pos++;
            if(N&1==1){
                if(fir_pos!=-1){
                    int tmp = pos-fir_pos;
                    max_len=max_len>tmp?max_len:tmp;
                }
                fir_pos=pos;
            }
            N=N>>1;
        }
        return max_len;
    }
};