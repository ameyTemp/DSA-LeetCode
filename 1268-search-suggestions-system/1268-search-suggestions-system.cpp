struct TrieNode{
    TrieNode* children[26];
    vector<int> index;
    
    bool isPresent(char c){
        return (children[c-'a']!=NULL);
    }
};

class Solution {
private:
    TrieNode* root;
public:
    
    vector<int> search(string word){
        TrieNode* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->isPresent(word[i]))
                return {};
            temp = temp->children[word[i]-'a'];
        }
        return temp->index;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        vector<vector<string>> res(searchWord.length());
        int n = products.size();
        for(int i=0;i<n;i++){
            TrieNode* node  = root;
            string word= products[i];
            for(int j=0;j<word.length();j++){
                if(!node->isPresent(word[j])){
                    node->children[word[j]-'a'] = new TrieNode();
                }
                node->index.push_back(i);
                node = node->children[word[j]-'a'];
            }
            node->index.push_back(i);
        }
        
        string temp = "";
        for(int i=0;i<searchWord.length();i++){
            temp+=searchWord[i];
            vector<int> ind = search(temp);
            for(int x:ind){
                res[i].push_back(products[x]);
            }
            sort(res[i].begin(),res[i].end());
            if(res[i].size()>3)
                res[i].resize(3);
        }
        return res;
    }
};