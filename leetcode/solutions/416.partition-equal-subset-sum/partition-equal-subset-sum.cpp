class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // tricky with bitset
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum&1) return false;
        bitset<100*200/2+1> bit(1);
        for (int num:nums) bit |= bit<<num;
        return bit[sum>>1];
    }
};