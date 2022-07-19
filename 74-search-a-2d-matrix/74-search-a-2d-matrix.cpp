class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l=0,r=n*m-1;
        while(l!=r){
            int mid = (l+r-1)/2;
            if(matrix[mid/m][mid%m]==target){
                return true;
            }else if(target>matrix[mid/m][mid%m]){
                l=mid+1;
            }else {
                r=mid;
            }
        }
        return matrix[r/m][r%m]==target;
        
    }
};