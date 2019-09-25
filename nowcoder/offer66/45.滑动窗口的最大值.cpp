
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> q;
        for(int i=0;i<num.size();i++){
            while(q.size() && num[q.back()]<num[i])
                q.pop_back();
            if(q.size() && i-q.front()+1>size)
                q.pop_front();
            q.push_back(i);
            if(size && i+1>=size){
                res.push_back(num[q.front()]);
            }
        }
        return res;
         
    }
};
