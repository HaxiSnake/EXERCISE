
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size()<=0) return 0;
        int left=0,right=data.size();
        int mid = (left + right)/2;
        bool dec;
        if(data[left] <= data[right]){
            dec=false;
        }else{
            dec=true;
        }
        while(left<=right && data[mid]!=k){
            if( data[mid] > k ){
                if(dec){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else if( data[mid] < k ){
                if(dec){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            mid = ( left + right )/2;
        }
        if(data[mid]!=k || left>right) return 0;
        int l_k=mid, r_k=mid;
        while( l_k>=0 && data[l_k] == k){
            l_k--;
        }
        while( r_k<data.size() && data[r_k] == k){
            r_k++;
        }
        return r_k-l_k-1;
    }
};
