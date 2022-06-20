struct TrieNode{
    TrieNode* children[26];
    bool endofword=false;
    int len=0;
    
    bool isPresent(char c){
        return (children[c-'a']!=NULL);
    }
};
class Solution {
private:
    TrieNode* root;
public:
    static bool comparator(string s1,string s2){
        return s1.length()>s2.length();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),comparator);
        root = new TrieNode();
        int n = words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string word = words[i];
            TrieNode* temp  = root;
            bool add=false;
            for(int j=word.length()-1;j>=0;j--){
                if(!temp->isPresent(word[j])){
                    temp->children[word[j]-'a'] = new TrieNode();
                    if(!add){
                        ans+=word.length()+1;
                        add=true;
                    }
                }
                temp = temp->children[word[j]-'a'];
            }
        }
        // TrieNode* node = root;
        // for(int i=0;i<26;i++){
        //     if(root->children[i]!=NULL)
        //         cout<<root->children[i]<<endl;
        // }
        return ans;
    }
};