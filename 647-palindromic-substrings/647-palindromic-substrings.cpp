class Solution {
public:
    int countSubstrings(string s) {
        //Non Dynamic Programming Solution
        
        // int count = 0;
        // int n = s.length();
        // for(int i=0;i<n;i++){
        //     int l = i,r=i;
        //     //for odd length palindromes
        //     while(l>=0 and r<n and s[l]==s[r]){
        //         count++;
        //         l--;
        //         r++;
        //     }
        //     l=i;
        //     r=i+1;
        //     while(l>=0 and r<n and s[l]==s[r]){
        //         count++;
        //         l--;
        //         r++;
        //     }
        // }
        // return count;
        
        //Dynamic Programming Solution
        
        int count = 0 ;
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            count++;
        }
        for(int col=1;col<n;col++){
            for(int row=0;row<col;row++){
                if(row==col-1 and s[row]==s[col]){
                    dp[row][col]=1;
                    count++;
                }
                if(s[row]==s[col] and dp[row+1][col-1]==1){
                    dp[row][col]=1;
                    count++;
                }
            }
        }
        return count;
    }
    };