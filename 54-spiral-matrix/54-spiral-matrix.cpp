class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int i=0,j=0;
        int endr=n,endc=m,startr=0,startc=0;
        int count=0;
        while(count<n*m){
            if(i==startr and j==startc){
                for(int x=j;x<endc;x++){
                    cout<<matrix[i][x]<<" ";
                    ans.push_back(matrix[i][x]);
                    count++;
                    if(count==n*m){
                        return ans;
                    }
                }
                j=endc;
                startr++;
                i=startr;
            }
            if(i==startr and j==endc){
                for(int x=i;x<endr;x++){
                    cout<<matrix[x][j-1]<<" ";
                    ans.push_back(matrix[x][j-1]);
                    count++;
                    if(count==n*m)
                        return ans;
                }
                i=endr;
                endc--;
                j=endc;
            }
            if(i==endr and j==endc){
                for(int x=j-1;x>=startc;x--){
                    cout<<matrix[i-1][x]<<" ";
                    ans.push_back(matrix[i-1][x]);
                    count++;
                    if(count==n*m)
                        return ans;
                }
                endr--;
                i=endr;
                j=startc;
            }
            if(i==endr and j==startc){
                for(int x=i-1;x>=startr;x--){
                    cout<<matrix[x][j]<<" ";
                    ans.push_back(matrix[x][j]);
                    count++;
                    if(count==n*m)
                        return ans;
                }
                startc++;
                j=startc;
                i=startr;
            }
        }
        return ans;
    }
};