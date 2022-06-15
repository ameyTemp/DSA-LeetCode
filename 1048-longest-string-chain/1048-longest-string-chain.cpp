class Solution {
public:
    static bool comparator(string s1,string s2){
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comparator);
        int n = words.size();
        int res=0;
        if(n==1)
            return 1;
        unordered_map<string,int> dp;
        for(string s:words){
            for(int j=0;j<s.length();j++){
                string temp = s.substr(0,j) + s.substr(j+1);
                if(dp.find(temp)==dp.end()){
                    dp[s] = max(dp[s],1);
                }else{
                    dp[s] = max(dp[s],dp[temp]+1);
                }
            }
            res=max(res,dp[s]);
        }
        return res;
    }
};