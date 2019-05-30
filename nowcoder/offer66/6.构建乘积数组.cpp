
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(),1);
        vector<int> C(A.size(),1);
        B[0]=1;
        C[A.size()-1]=1;
        for(int i=1;i<A.size();i++){
            B[i]=B[i-1]*A[i-1];
            C[A.size()-i-1]=C[A.size()-i]*A[A.size()-i];
        }
        for(int i=0;i<A.size();i++){
            B[i]=B[i]*C[i];
        }
        return B;
    }
};
