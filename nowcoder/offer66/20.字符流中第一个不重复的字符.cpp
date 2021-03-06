
class Solution
{
private:
    queue<char> data;
    int cnt[128];
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         cnt[ch-' ']++;
        if(cnt[ch-' ']==1){
            data.push(ch);
        }
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!data.empty() && cnt[data.front()-' ']>1) data.pop();
        if(data.empty()) return '#';
        else return data.front();
    }
    Solution(){
        memset(cnt,0,sizeof(cnt));
    }
 
};
