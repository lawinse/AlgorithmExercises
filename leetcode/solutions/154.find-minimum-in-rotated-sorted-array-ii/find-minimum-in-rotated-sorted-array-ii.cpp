class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int left = 0;
        int right = len-1;
        while (left < right) {
            while(left < right && nums[left + 1] == nums[left]) left++;
            while(left < right && nums[right - 1] == nums[right]) right--;
            int m = left + (right-left)/2;
            if (nums[m] > nums[right]) left = m+1;
            else right = m;
        }
        return nums[left];
    }
};