class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        ret.clear();
        ret.push_back(nums);
        if (n <= 1) {return ret;}
        while(1)
        {
            int i,j;
            for (i = n-2; i >=0 && nums[i] >= nums[i+1]; --i);
            if(i>=0) {
                for (j = n-1; j >= i&& nums[j] <= nums[i];--j);
                swap(nums[i],nums[j]),reverse(nums.begin()+i+1,nums.end()),ret.push_back(nums);
            }
            else break;
        }
        return ret;
    }
};