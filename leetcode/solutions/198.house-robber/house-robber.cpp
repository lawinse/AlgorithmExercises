class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        int nr[n] = {0},r[n] = {0};
        nr[0] = 0;
        r[0] = nums[0];
        for (int i=1; i<nums.size(); ++i){
            r[i] = nr[i-1]+nums[i];
            nr[i] = max(nr[i-1],r[i-1]);
        }
        return max(r[n-1],nr[n-1]);
    }
};