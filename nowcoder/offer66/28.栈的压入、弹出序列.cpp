
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        int j=0;
        for(int i=0;i<pushV.size();i++){
            s.push(pushV[i]);
            while( (!s.empty()) && j<popV.size() && (s.top()==popV[j]) ){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
