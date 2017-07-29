class Solution {
public:
    vector<int>self;
    Solution(vector<int> nums) {
        srand(time(0));
        self = nums;
    }
    
    int pick(int target) {
        int cnt = 0;
        int ret;
        for (int i=0; i<self.size(); ++i) {
            if (self[i] == target && rand()%(++cnt) == 0) ret = i;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */