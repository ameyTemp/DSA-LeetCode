class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> arr(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0)
                    continue;
                if(word1[i-1]==word2[j-1]){
                    arr[i][j] = 1 + arr[i-1][j-1];
                }else{
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return m+n-2*arr[n][m];
    }
};