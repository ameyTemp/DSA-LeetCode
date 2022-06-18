struct TrieNode{
    TrieNode* children[26];
    bool endofword=false;
    
    bool ispresent(char ch){
        return (children[ch-'a']!=NULL);
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root =  new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            if(!temp->ispresent(word[i])){
                TrieNode* temp1 = new TrieNode();
                temp->children[word[i]-'a']=temp1;
            }
            temp = temp->children[word[i]-'a'];
        }
        temp->endofword=true;
        return;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            
            if(!node->ispresent(word[i]))
                return false;
            node = node->children[word[i]-'a'];
        }
        if(node->endofword){
            return true;
        }
        return false;
    }
    
    bool startsWith(string preTfix) {
        TrieNode* node  = root;
        for(int i=0;i<preTfix.length();i++){
            if(!node->ispresent(preTfix[i]))
                return false;
            node = node->children[preTfix[i]-'a'];
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