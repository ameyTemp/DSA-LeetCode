class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minHeap;
        for(int i=0;i<min(n,k);i++){
            minHeap.push({matrix[i][0],i,0});
        }
        int ans;
        for(int i=0;i<k;i++){
            vector<int> temp = minHeap.top();
            minHeap.pop();
            int r = temp[1],c=temp[2];
            ans = temp[0];
            if(c+1<n){
                minHeap.push({matrix[r][c+1],r,c+1});
            }
        }
        return ans;
    } 
};