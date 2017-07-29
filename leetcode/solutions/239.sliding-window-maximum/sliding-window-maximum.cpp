class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0) return vector<int>{};
        vector<int> ret;
        deque<int> Q;
        for (int i=0; i<nums.size(); ++i) {
            while(!Q.empty() && nums[i] > nums[Q.back()]) Q.pop_back();
            Q.push_back(i);
            if (i-Q.front()+1 > k) Q.pop_front();
            if (i>=k-1) ret.push_back(nums[Q.front()]);
        }
        
        return ret;
    }
};