class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        int sum=0;
        int pow = 1;
        int ans=0;
        for(int i=n-1;i>=0 and sum+pow<=k;i--){
            if(s[i]=='1'){
                ans++;
                sum+=pow;
            }
            pow=pow<<1;
        }
        int ans1 = count(s.begin(),s.end(),'0');
        return ans1+ans;
    }
};