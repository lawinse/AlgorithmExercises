class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return;
        int beg = 0,i=0;
        for (;i<len; ++i) {
            if (nums[i] != 0) {
                nums[beg++] = nums[i];
            }
        }
        for (;beg<len;++beg) nums[beg] = 0;
        return ;
    }
};