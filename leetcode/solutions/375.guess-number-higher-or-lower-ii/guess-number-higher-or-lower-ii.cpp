class Solution {
public:
    int getMoneyAmount(int n) {
        const int N = n;
        int dp[N+1][N+1] = {0};
        for (int i=1; i<=N; ++i)
        for (int j=i-1; j>0; --j) {
            int ret = INT_MAX;
            for (int k=j; k<=i;++k){
                ret = min(ret, k +max(dp[j][k-1], dp[k+1][i]));
            }
            dp[j][i] = ret;
        }
        
        return dp[1][N];
    }
};