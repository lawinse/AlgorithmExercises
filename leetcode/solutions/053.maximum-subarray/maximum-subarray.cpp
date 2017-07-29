class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int thisSum = 0,maxSum = 0x80000000;
        for (auto num:nums){
            thisSum += num;
            
            if (thisSum > maxSum) maxSum = thisSum;
            if (thisSum < 0) thisSum = 0;
        }
        
        return maxSum;
    }
};