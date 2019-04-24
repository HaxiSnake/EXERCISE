class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for(int i=A.size()-2;i>=0;i--){
            if(A[i]>A[i+1]){
                int j=0;
                int tmp=A[i];
                for(j=i+1;j<A.size();j++){
                    if(A[j]>tmp){
                        break;  
                    }
                }
                reverse(A.begin(),A.begin()+i+1);
                reverse(A.begin(),A.begin()+j);
                reverse(A.begin(),A.begin()+j-1);
                res.push_back(i+1);
                res.push_back(j);  
                res.push_back(j-1);
                // for(auto num:A){
                //     cout<<num<<" ";
                // }
                cout<<endl;
            }
        }
        return res;
    }
};