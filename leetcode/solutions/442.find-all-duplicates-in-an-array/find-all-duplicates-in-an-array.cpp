class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret;
        if (len < 2) return ret;
        for (int i=0; i<len;) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else ++i;
        }
        for (int i=0; i<len; ++i) if (nums[i] != i+1) ret.push_back(nums[i]);
        return ret;
    }
};