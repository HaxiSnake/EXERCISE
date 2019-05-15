class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        int pA=0,pB=0;
        while(pA<A.size() && pB<B.size()){
            int maxn=min(A[pA][1],B[pB][1]);
            int minn=max(A[pA][0],B[pB][0]);
            if(minn<=maxn){
                res.push_back({minn,maxn});
            }
            if(maxn==A[pA][1]){
                pA++;
            }else{
                pB++;
            }
        }
        return res;
    }
};