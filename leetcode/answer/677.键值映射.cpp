class MapSum {
private:
    map<string,int> MyMap;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        MyMap[key]=val;
    }
    
    int sum(string prefix) {
        int sum=0;
        map<string,int>::iterator iter;
        iter=MyMap.begin();
        while(iter!=MyMap.end()){
            if(isPrefix(prefix,iter->first)){
                sum+=iter->second;
            }
            iter++;
        }
        return sum;
    }
    bool isPrefix(string prefix,string object){
        if(prefix.length()>object.length()) return false;
        for(int i=0;i<prefix.length();i++){
            if (prefix[i]!=object[i])
                return false;
        }
        return true;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */