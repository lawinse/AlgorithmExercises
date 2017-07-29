class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nlen = nums.size();
        int i,j;
        if (nlen < 2) return;
        for (i = nlen-2; i >=0; --i){
            if (nums[i] < nums[i+1]) break;
        }
        for (j = nlen -1; j >= i; --j){
            if (nums[j] > nums[i]) break;
        }
        if (i >= 0) swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
        //return nums;
    }
};