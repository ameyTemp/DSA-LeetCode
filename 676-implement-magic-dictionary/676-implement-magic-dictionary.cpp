struct TrieNode{
    TrieNode* children[26]; 
    bool endofword = false;
    
    bool isPresent(char ch){
        return (children[ch-'a']!=NULL);
    }
};
class MagicDictionary {
private:
    TrieNode* root;
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    void insert(string word){
        int n = word.length();
        TrieNode* node = root;
        for(int i=0;i<n;i++){
            if(!node->isPresent(word[i])){
                node->children[word[i]-'a']=new TrieNode() ;  
            }
            node = node->children[word[i]-'a'];
        }
        node->endofword=true;
    }
    void buildDict(vector<string> dictionary) {
        int n = dictionary.size();
        TrieNode* temp = root;
        for(int i=0;i<n;i++){
            insert(dictionary[i]);
        }
    }
    bool find(string word){
        TrieNode* node = root;
        int n = word.length();
        for(int i=0;i<n;i++){
            if(!node->isPresent(word[i])){
                return false;
            }
            node = node->children[word[i]-'a'];
        }
        return node->endofword;
    }  
    bool search(string searchWord) {
        int n = searchWord.length();
        TrieNode* node = root;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                char c = j + 'a';
                char temp = searchWord[i];
                if(temp==c)
                    continue;
                searchWord[i] = c;
                // cout<<searchWord<<endl;
                if(find(searchWord))
                    return true;
                searchWord[i] = temp;
            }
        }
        // cout<<find("leetcode")<<endl;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */