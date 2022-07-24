class Solution {
public:
    
    void dfs(int i,int j,int preH,set<pair<int,int>>& vis,vector<vector<int>>& heights){
        if( i<0 or j<0 or  i==heights.size() or j==heights[0].size() or heights[i][j]<preH or vis.find({i,j})!=vis.end())
            return;
        vis.insert({i,j});
        dfs(i-1,j,heights[i][j],vis,heights);
        dfs(i+1,j,heights[i][j],vis,heights);
        dfs(i,j-1,heights[i][j],vis,heights);
        dfs(i,j+1,heights[i][j],vis,heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();
        
        set<pair<int,int>> pac;
        set<pair<int,int>> atl;
        
        for(int i=0;i<c;i++){
            dfs(0,i,heights[0][i],pac,heights);
            dfs(r-1,i,heights[r-1][i],atl,heights);
        }
        
        for(int i=0;i<r;i++){
            dfs(i,0,heights[i][0],pac,heights);
            dfs(i,c-1,heights[i][c-1],atl,heights);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pac.find({i,j})!=pac.end() and atl.find({i,j})!=atl.end())
                    ans.push_back({i,j});
            }
        }
        
        return ans;
    }
};