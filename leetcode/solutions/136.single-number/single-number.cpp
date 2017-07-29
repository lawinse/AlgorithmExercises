class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it) ret ^= *it;
        return ret;
    }
};