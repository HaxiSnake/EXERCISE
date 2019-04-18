class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> prepos(71,-1);
        int max=T.back();
        vector<int> res(T.size(),0);
        for(int i=T.size()-1;i>=0;i--){
            if(T[i]>=max){
                max=T[i];
                res[i]=0;
                prepos[T[i]-30]=i;
            }else{
                prepos[T[i]-30]=i;
                int latest=30001;
                for(int j=T[i]+1;j<=max;j++){
                    int idx=j-30;
                    if(prepos[idx]!=-1){
                        if(prepos[idx]<latest){
                            latest=prepos[idx];
                        }
                    }
                }
                res[i]=latest-i;
            }
        }
        return res;
    }
};