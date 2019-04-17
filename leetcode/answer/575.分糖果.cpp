class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int> candyset;
        for(auto candy:candies){
            candyset.insert(candy);
        }
        if(candyset.size()>candies.size()/2){
            return candies.size()/2;
        }else{
            return candyset.size();
        }
    }
};