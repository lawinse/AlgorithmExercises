class Solution {
public:
    int **dp;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        dp = new int *[m+2];
        for (int i = 0 ; i < m+2; ++i) dp[i] = new int[n+2],memset(dp[i],0,sizeof (int) * (n+2));
       // memset(dp,0,sizeof(int) *(m+2)*(n+2));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j){
            if (i == 0 && j == 0) continue;
            dp[i][j] = grid[i][j] + min(i?dp[i-1][j]:1<<30,j?dp[i][j-1]:1<<30);
        }
        int ans = dp[m-1][n-1];
        for (int i = 0; i < m+2; ++i) delete [] dp[i];
        delete [] dp;
        return ans;
        
    }
};