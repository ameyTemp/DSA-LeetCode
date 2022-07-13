class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            int x=0,y=i;
            while(x<n and x>=0 and y>=0 and y<m){
                if(grid[x][y]==1 and y<m-1 and grid[x][y+1]==1){
                    x++;
                    y++;
                }else if(grid[x][y]==-1 and y>0 and grid[x][y-1]==-1){
                    x++;
                    y--;
                }else if(grid[x][y]==1 and (y==m-1 or grid[x][y+1]==-1)){
                    ans[i]=-1;
                    break;
                }else if(grid[x][y]==-1 and (y==0 or grid[x][y-1]==1)){
                    ans[i]=-1;
                    break;
                }
            }
            if(ans[i]==0){
                ans[i]=y;
            }
        }
        
        return ans;
    }
};