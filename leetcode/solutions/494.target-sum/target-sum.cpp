class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return (abs(sum) < abs(S) || (S+sum)&1) ? 0:subsetsum(nums, (S+sum)/2);
    }
    
    int subsetsum(vector<int>& nums, const int sum) {
        int *dp = new int [sum+1];
        memset(dp, 0, sizeof(int)*(sum+1));
        dp[0] = 1;
        for (auto n:nums) {
            for (int i=sum; i>=n; --i) 
                dp[i] += dp[i-n];
        }
        int ret = dp[sum];
        
        delete []dp;
        return ret;
    }
};