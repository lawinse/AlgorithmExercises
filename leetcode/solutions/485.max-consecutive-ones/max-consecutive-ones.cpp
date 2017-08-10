class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return 0;
        int cur = 0, ans = 0;
        for (auto it:nums) {
            if (it == 1) cur++;
            else ans = max(cur, ans), cur = 0;
        }
        return max(ans,cur);
    }
};