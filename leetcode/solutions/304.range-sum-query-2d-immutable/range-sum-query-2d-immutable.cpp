class NumMatrix {
public:
    int **f;
    int m,n;
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        if (m == 0) return;
        n = matrix[0].size();
        if (n == 0) return;
        f = new int*[m+5];
        for (int i=0; i<=m; ++i){
            f[i] = new int [n+5];
            // memset(f[i],0,sizeof(int)*(n+5));
            // f[i][0] = 0;
            // for (int j=1; j<=n; ++j) f[i][j] = matrix[i-1][j-1];
        }
        for (int i=0; i<=m; ++i) f[i][0] = 0;
        for (int j=0; j<=n; ++j) f[0][j] = 0;
        for (int i=1; i<=m ;++i)
        for (int j=1; j<=n; ++j)
            f[i][j] = f[i-1][j]+f[i][j-1]-f[i-1][j-1] + matrix[i-1][j-1];
        
        
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        if (m==0 || n==0) return 0;
        // return 0;
        return f[row2+1][col2+1] - f[row2+1][col1] - f[row1][col2+1] + f[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);