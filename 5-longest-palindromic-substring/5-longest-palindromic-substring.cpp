class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        res.push_back(s[0]);
        int len = 1;
        int n = s.length();
        for(int i=0;i<n;i++){
            int l = i,r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    res=s.substr(l,len);
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    res=s.substr(l,len);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};