class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        const int n = nums.size();
        int dp[n][n] = {};
        for (int len = 2; len < n; ++len){
            for (int i = 0; i+len < n; ++i){
                int j = i+len;
                for (int m = i+1; m<j; ++m){
                    dp[i][j] = max(dp[i][j],dp[i][m]+dp[m][j]+nums[i]*nums[m]*nums[j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};