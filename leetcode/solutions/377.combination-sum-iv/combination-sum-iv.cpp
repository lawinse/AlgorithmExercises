class Solution {
public:
    unordered_map<int,int> hashmap;
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        if (target == 0) return 1;
        auto found = hashmap.find(target);
        if (found!= hashmap.end()) {return found->second;}
        int ret = 0;
        for (int num:nums) {
            if (target >= num) ret += combinationSum4(nums,target-num);
        }
        return hashmap[target] = ret;
    }
};