struct TrieNode{
    TrieNode* children[27];
    int index=0;
    
    bool isPresent(char ch){
        return (children[ch-'a']!=NULL);
    }
};
class WordFilter {
private:
    TrieNode* root;
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for(int x=0;x<words.size();x++){
            string word = words[x] + "{";
            for(int i=0;i<word.length();i++){
                TrieNode* node = root;
                node->index = x;
                for(int j=i;j<2*word.length()-1;j++){
                    char c = word[j%word.length()];
                    if(!node->isPresent(c)){
                        node->children[c-'a'] = new TrieNode();
                    }
                    node = node->children[c-'a'];
                    node->index = x;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string search = suffix + "{" + prefix;
        TrieNode* node = root;
        for(int i=0;i<search.length();i++){
            if(!node->isPresent(search[i]))
                return -1;
            node = node->children[search[i]-'a'];
        }
        return node->index;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */