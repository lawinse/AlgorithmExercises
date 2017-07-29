class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ret.emplace_back(nums);
        while(1) {
            int i,j;
            for (i=n-2; i>=0 && nums[i+1] <= nums[i]; --i);
            if (i < 0) break;
            for (j = n-1; j>=i && nums[j] <= nums[i]; --j);
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
            ret.emplace_back(nums);
        }
        return ret;
    }
};