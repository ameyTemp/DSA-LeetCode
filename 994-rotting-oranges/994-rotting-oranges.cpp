class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0,time=0;
        
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    fresh++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        // cout<<fresh<<endl;
        while(!q.empty() and fresh>0){
            
            int len = q.size();
            for(int i=0;i<len;i++){
                pair<int,int> ind = q.front();
                q.pop();
                if(ind.first-1>=0 and ind.first-1<n and ind.second>=0 and ind.second<m and grid[ind.first-1][ind.second]==1){
                    grid[ind.first-1][ind.second]=2;
                    q.push({ind.first-1,ind.second});
                    fresh--;
                }
                if(ind.first+1>=0 and ind.first+1<n and ind.second>=0 and ind.second<m and grid[ind.first+1][ind.second]==1){
                    grid[ind.first+1][ind.second]=2;
                    q.push({ind.first+1,ind.second});
                    fresh--;
                }
                if(ind.first>=0 and ind.first<n and ind.second-1>=0 and ind.second-1<m and grid[ind.first][ind.second-1]==1){
                    grid[ind.first][ind.second-1]=2;
                    q.push({ind.first,ind.second-1});
                    fresh--;
                }
                if(ind.first>=0 and ind.first<n and ind.second+1>=0 and ind.second+1<m and grid[ind.first][ind.second+1]==1){
                    grid[ind.first][ind.second+1]=2;
                    q.push({ind.first,ind.second+1});
                    fresh--;
                }
            }
            // cout<<q.size()<<endl;
            time++;
        }
        
        if(fresh>0)
            return -1;
        return time;
    }
    
};