class Solution {
public:
    string frequencySort(string s) {
        map<char,int> counter;
        for(auto ch:s){
            if(counter.find(ch)==counter.end()){
                counter[ch]=1;
            }else{
                counter[ch]++;
            }
        }
        
        vector<pair<char,int>> counter_v(counter.begin(),counter.end());
        sort(counter_v.begin(),counter_v.end(),_compare);
        string res="";
        for(int i=0;i<counter_v.size();i++){
            string tmp="";
            for(int j=0;j<counter_v[i].second;j++){
                tmp+=counter_v[i].first;
            }
            res+=tmp;
        }
        return res;
    }
    private:
    static bool _compare(const pair<char,int> &p1,const pair<char,int> &p2){
        return p1.second > p2.second;
    }
};