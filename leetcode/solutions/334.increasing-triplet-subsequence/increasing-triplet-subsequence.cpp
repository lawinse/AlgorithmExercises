class Solution {
private:
    bool LIS_3(vector<int> & nums) {
        vector<int> ret;
        ret.push_back(INT_MIN);
        for (auto num : nums) {
            if (num>ret.back()) {
                ret.push_back(num);
            } else {
                auto found = lower_bound(ret.begin(),ret.end(),num);
                *found = num;
            } 
            
            if (ret.size() >= 4) return true;
        }
        return false;
    }
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return false;
        return LIS_3(nums);
    }
};