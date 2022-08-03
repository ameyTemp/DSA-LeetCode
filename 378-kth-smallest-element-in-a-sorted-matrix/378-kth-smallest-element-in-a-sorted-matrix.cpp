class Solution {
public:
    int lessthanorequal(vector<vector<int>> matrix,int num){
        int n = matrix.size();
        int count=0;
        for(int r=0;r<n;r++){
            int c = n-1;
            while(c>=0 and matrix[r][c]>num){
                c--;
            }
            count+=c+1;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int h = matrix[n-1][n-1];
        int ans;
        while(l<=h){
            int mid = (l+h)/2;
            if(lessthanorequal(matrix,mid)>=k){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    } 
};