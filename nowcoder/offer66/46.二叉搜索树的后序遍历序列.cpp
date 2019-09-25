
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()<=0) return false;
           return _verify(0,sequence.size()-1,sequence);
    }
    bool _verify(int start,int end,vector<int>& sequence){
        if(start>end) return true;
        int i=end-1;
        for(i=end-1;i>=start;i--){
            if(sequence[i]<sequence[end]) break;
        }
        for(int j=start;j<=i;j++){
            if(sequence[j]>sequence[end]) return false;
        }
        return _verify(start,i,sequence) && _verify(i+1,end-1,sequence);
    }
};
