class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> sub;
        int n = s.length();
        // cout<<end;
        if(n<k)
            return false;
        string str=s.substr(0,k);
        sub.insert(str);
        for(int i=k-1;i<n;i++){
            str.erase(0,1);
            str.push_back(s[i]);
            sub.insert(str);
        }
        if(sub.size()==pow(2,k))
            return true;
        return false;
    }
};