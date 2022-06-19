struct TrieNode{
    TrieNode* children[26];
    vector<int> index;
    bool endofword=false;
    
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
        vector<vector<string>> res;
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
            node->endofword=true;
        }
        
        string temp = "";
        for(int i=0;i<searchWord.length();i++){
            temp+=searchWord[i];
            vector<int> ind = search(temp);
            vector<string> subres;
            for(int x:ind){
                // cout<<products[x]<<endl;
                subres.push_back(products[x]);
            }
            // cout<<endl;
            sort(subres.begin(),subres.end());
            if(subres.size()>3)
                subres.resize(3);
            res.push_back(subres);
        }
        return res;
    }
};