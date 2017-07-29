class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        stack<int>S;
        int s3 = INT_MIN;
        for (int i=len-1; i>=0; --i) {
            if (nums[i] < s3) return true;
            else {
                while (!S.empty() && nums[i]>S.top()) s3 = S.top(), S.pop();
            }
            S.push(nums[i]);
        }
        return false;
    }
};