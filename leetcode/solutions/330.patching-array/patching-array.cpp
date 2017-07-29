class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1; int i = 0, add = 0;
        while(miss <= n) {
            if (i<nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else miss *= 2, add++;
        }
        return add;
    }
};