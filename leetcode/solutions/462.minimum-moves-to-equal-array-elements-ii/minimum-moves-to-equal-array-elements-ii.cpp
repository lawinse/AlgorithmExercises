class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int n = nums.size();
        for (int i=0; i<n/2; ++i) {
            ret += nums[n-1-i]-nums[i];
        }
        return ret;
    }
};