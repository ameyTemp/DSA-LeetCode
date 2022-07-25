class Solution {
public:
    bool checkCycle(int v,vector<int> &visited,vector<vector<int>> &adj){
        if(visited[v]==1){
            return true;
        }
        if(visited[v]==2){
            return false;
        }
        visited[v]=1;
        for(int i:adj[v]){
            if(checkCycle(i,visited,adj)){
                return true;
            }
        }
        visited[v]=2;
        return false;
    }
    
    void dfs(int v,vector<vector<int>> adj,vector<int> &vis,stack<int> &s){
        if(vis[v]==1){
            return;
        }
        
        for(int i:adj[v]){
            if(vis[i]==0)
                dfs(i,adj,vis,s);
        }
        s.push(v);
        vis[v]=1;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        vector<int> visited(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int flag=0;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                bool a=checkCycle(i,visited,adj);
                if(a==true){
                    flag=1;
                    break;
                }
            }
        }
        vector<int> ans;
        if(flag==1){
            return ans;
        }
        
        stack<int> s;
        vector<int> vis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                dfs(i,adj,vis,s);
            }
        }
        
        while(s.size()!=0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};