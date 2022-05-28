class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() ;   //Rows
        int n = obstacleGrid[0].size(); //Columns
        vector<vector<int>> dp(m,vector<int>(n,0));
        bool flag=false;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1){
                dp[0][i]=0;
                flag=true;
            }
            else if(!flag){
                dp[0][i]=1;
            }else{
                dp[0][i]=0;                
            }
        }
        flag=false;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                dp[i][0]=0;
                flag=true;
            }
            else if(!flag){
                dp[i][0]=1;
            }else{
                dp[i][0]=0;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(obstacleGrid[j][i]==1){
                    dp[j][i]=0;
                }else{
                    dp[j][i] = dp[j-1][i] + dp[j][i-1];
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};