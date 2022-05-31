class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> sub;
        int n = s.length();
        // cout<<end;
        if(n<k)
            return false;
        for(int i=0;i<n-k+1;i++){
            string temp = s.substr(i,k);
            sub.insert(temp);
        }
        
        if(sub.size()==pow(2,k))
            return true;
        return false;
    }
};