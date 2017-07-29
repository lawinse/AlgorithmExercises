class Solution {
typedef long long LL;
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if (len <= 2) return 0;
        int ret = 0;
        vector<unordered_map<LL,int>> dp(len);
        for (int i=1; i<len; ++i){
            for (int j=i-1; j>=0; --j) {
                LL diff = (LL)A[i]-(LL)A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                if (dp[j].find(diff) != dp[j].end()) {
                    ret += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                ++dp[i][diff];
            }
        }
        return ret;
    }
};