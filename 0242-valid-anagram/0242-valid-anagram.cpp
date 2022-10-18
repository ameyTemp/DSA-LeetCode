class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> a,b;
        int n = s.length();
        for(int i=0;i<n;i++){
            a[s[i]]++;
            b[t[i]]++;
        }
        if(s.length()==t.length() && a==b)
            return true;
        return false;
    }
};