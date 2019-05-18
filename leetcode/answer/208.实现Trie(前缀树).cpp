class TrieNode{
    public:
    int count;
    map<char,TrieNode*> children;
    TrieNode(int x){
        count=x;
    }
};

class Trie {
private:
    TrieNode* head;
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new TrieNode(0);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *tmp=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(tmp->children.find(ch)==tmp->children.end()){
                tmp->children[ch]=new TrieNode(0);
            }
            if(i==word.length()-1){
                tmp->children[ch]->count++;
            }
            tmp=tmp->children[ch];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p=head;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(p->children.find(ch)==p->children.end()){
                return false;
            }
            if(i==word.length()-1){
                if(p->children[ch]->count==0)
                    return false;
                else 
                    return true;
            }
            p=p->children[ch];
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p=head;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            if(p->children.find(ch)==p->children.end()){
                return false;
            }
             p=p->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */