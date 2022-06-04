class Solution {
public:
    void solve(int col,vector<string>& board,int n,vector<int>& left,vector<int>& ld,vector<int>& ud,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            //Condition for queen to be placed
            if(left[i]==0 and ud[n-1+col-i]==0 and ld[col+i]==0){
                left[i]=1;
                ud[n-1+col-i]=1;
                ld[col+i]=1;
                //Placing the Queen
                board[i][col]='Q';
                //Recurse to next column
                solve(col+1,board,n,left,ld,ud,ans);
                //Backtrack
                board[i][col]='.';
                left[i]=0;
                ld[i+col]=0;
                ud[n-1+col-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> left(n,0);
        vector<int> ud(2*n-1,0);
        vector<int> ld(2*n-1,0);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,n,left,ld,ud,ans);
        return ans;
    }
};