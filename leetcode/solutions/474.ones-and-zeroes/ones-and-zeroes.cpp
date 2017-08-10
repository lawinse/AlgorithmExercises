class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+2][n+2];
        memset(dp,0,sizeof(dp));
        for (string s:strs) {
            int nums[2] = {0};
            for (char c:s) {
                nums[c-'0']++;
            }
            
            for (int i=m; i>=nums[0]; --i)
                for (int j=n; j>=nums[1];--j) {
                    dp[i][j] = max(dp[i][j],dp[i-nums[0]][j-nums[1]]+1);
                }
            
        }
        return dp[m][n];
    }
};