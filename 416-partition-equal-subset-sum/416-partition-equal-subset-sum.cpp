class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        if(s%2==1)
            return false;
        s=s/2;
        vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            dp[i][0] = true;
        }
        
        for(int i=1;i<=s;i++){
            dp[0][i] = false;
        }
        for(int i=1;i<=n;i++){
             for(int j=1;j<=s;j++){
                 dp[i][j] = dp[i-1][j];
                 if(j>=nums[i-1])
                    dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
             }
        }
        
        return dp[n][s];
    }
};