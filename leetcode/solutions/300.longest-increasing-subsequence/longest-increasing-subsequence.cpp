class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        const int n = nums.size();
        if (n==0) return ret;
        vector<int> ans;
        for (auto num:nums){
            if (ans.size() == 0 || num>ans.back()) ans.push_back(num);
            else *lower_bound(ans.begin(),ans.end(),num) = num;
        }
        return ans.size();
        
    }
};