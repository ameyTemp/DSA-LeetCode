class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        sum = vector<vector<int>>(n,vector<int>(m,0));
        sum[0][0]=matrix[0][0];
        int r=sum[0][0],c=sum[0][0];
        for(int i=1;i<n;i++){
            r+=matrix[i][0];
            sum[i][0] = r;
        }
        for(int i=1;i<m;i++){
            c+=matrix[0][i];
            sum[0][i] = c;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] + matrix[i][j] - sum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0 and col1==0){
            return sum[row2][col2];
        }
        if(row1==0){
            return sum[row2][col2] - sum[row2][col1-1];    
        }
        if(col1==0){
            return sum[row2][col2] - sum[row1-1][col2];
        }
        int ans = sum[row2][col2]-sum[row1-1][col2]-sum[row2][col1-1]+sum[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */