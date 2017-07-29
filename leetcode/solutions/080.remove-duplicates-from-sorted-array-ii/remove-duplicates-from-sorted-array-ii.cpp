class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int quick = 1,slow = 0;
        int cnt = 1;
        while(quick < n){
            if (nums[quick] == nums[slow] && cnt == 1){
                nums[++slow] = nums[quick]; cnt = 2;
            }else if (nums[quick] != nums[slow]){
                nums[++slow] = nums[quick];
                cnt = 1;
            }
            ++quick;
        }
        return slow+1;
    }
};