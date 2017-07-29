void swap(int &a, int &b){a = a^b,b = a^b,a = a^b;}
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n  = nums.size();
        int i = 0;
        for (;i<n;){
            if(nums[i] < 0 || nums[i] > n || nums[i] == i+1 || nums[i] == nums[nums[i]-1]) ++i;
            else swap(nums[i],nums[nums[i]-1]);
        }
        for (i = 0; i < n && nums[i] == i+1; ++i);
        return i+1;
    }
};