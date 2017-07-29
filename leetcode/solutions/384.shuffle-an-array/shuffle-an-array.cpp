class Solution {
private:
    vector<int> raw;
    vector<int> cur;
public:
    Solution(vector<int> nums) {
        srand(time(0));
        raw = nums;
        cur = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return cur = raw;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        const int n = cur.size();
        for (int i=0; i<n; ++i) {
            swap(cur[i],cur[rand()%n]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */