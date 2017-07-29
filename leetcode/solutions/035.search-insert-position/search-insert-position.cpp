class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n;
        int mid;
        while(i < j){
            mid = i+((j-i)/2);
            if (mid == n) return n;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) j = mid;
            else i = mid+1;
        }
        return i;
    }
};