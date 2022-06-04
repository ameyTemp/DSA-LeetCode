class Solution {
private:
    void solve(int col,vector<string>& board,vector<int>& left,vector<int>& ld,vector<int>& ud,int& count,int n){
        if(col==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(left[i]==0 and ld[col+i]==0 and ud[n-1+col-i]==0){
                left[i]=1;
                ld[col+i]=1;
                ud[n-1+col-i]=1;
                board[i][col]='Q';
                solve(col+1,board,left,ld,ud,count,n);
                left[i]=0;
                ld[col+i]=0;
                ud[n-1+col-i]=0;
                board[i][col]='.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> left(n,0);
        vector<int> ld(2*n-1,0);
        vector<int> ud(2*n-1,0);
        int count=0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i]=s;
        solve(0,board,left,ld,ud,count,n);
        return count;
    }
};