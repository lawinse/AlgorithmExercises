class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if (n <= 1) return 0;
        int dp[3] = {0};
        int ndp[3] = {0};
        dp[0] = -prices[0];
        ndp[0] = 0;
        dp[1] = max(-prices[0],-prices[1]);
        ndp[1] = max(0,prices[1]-prices[0]);
        
        for (int i=2; i<n; ++i) {
            dp[i%3] = max(dp[(i-1)%3], ndp[(i-2)%3]-prices[i]);
            ndp[i%3] = max(ndp[(i-1)%3], dp[(i-1)%3] + prices[i]);
        }
        return ndp[(n-1)%3];
    }
};