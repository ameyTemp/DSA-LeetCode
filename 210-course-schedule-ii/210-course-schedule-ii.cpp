class Solution {
public:
    
    //0 -> not visited
    //1 -> visited 
    //2 -> visited and processed
    bool detectCycle_util(vector<vector<int>>& adjList,vector<int>& visited,int v){
        if(visited[v]==1)
            return true;
        if(visited[v]==2)
            return false;
        
        visited[v] = 1;
        for(int i=0;i<adjList[v].size();i++){
            if(detectCycle_util(adjList,visited,adjList[v][i]))
                return true;
        }
        visited[v]=2;
        return false;
    }
    bool detectCycle(vector<vector<int>>& adjList,int len){
        vector<int> visited(len,0);
        for(int i=0;i<len;i++){
            if(visited[i]==0){
                if(detectCycle_util(adjList,visited,i))
                    return true;
            }
        }
        return false;
    }
    void dfs(stack<int>& s,vector<vector<int>>& adjList,vector<int>& visited,int len,int v){
        
        if(visited[v]==1)
            return;
        for(int i=0;i<adjList[v].size();i++){
            if(visited[adjList[v][i]]==0)
                dfs(s,adjList,visited,len,adjList[v][i]);
        }
        visited[v]=1;
        s.push(v);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> ans;
        vector<vector<int>> adjList(numCourses);
        
        for(int i=0;i<n;i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> visited(numCourses,0);
        
        stack<int> num;
        if(detectCycle(adjList,numCourses)){
            return ans;
        }
        
        for(int i=0;i<numCourses;i++)
            dfs(num,adjList,visited,numCourses,i);
        
        while(!num.empty()){
            int t = num.top();
            ans.push_back(t);
            num.pop();
        }
        return ans;
    }
};