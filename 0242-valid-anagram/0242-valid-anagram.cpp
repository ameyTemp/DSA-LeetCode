class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> a;
        int n = s.length();
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<n;i++){
            a[s[i]]++;
            a[t[i]]--;
        }
        for(auto i:a){
            if(i.second)
                    return false;
        }
        
        return true;
    }
};