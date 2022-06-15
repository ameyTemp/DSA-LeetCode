class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int> dp(m+1);
        for(int i=0;i<=n;i++){
            vector<int> temp(m+1);
            for(int j=0;j<=m;j++){
                if(i==0 or j==0){
                    temp[j]=i+j;
                }else if(word1[i-1]==word2[j-1]){
                    temp[j]=dp[j-1];
                }else{
                    temp[j]=1+min(temp[j-1],dp[j]);
                }
            }
            dp=temp;
        }
        
        return dp[m];
    }
};