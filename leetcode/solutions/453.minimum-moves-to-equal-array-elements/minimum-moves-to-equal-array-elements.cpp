class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minx = INT_MAX;
        long long sum = 0;
        for (auto n:nums) {
            if (n<minx) minx = n;
            sum += n;
        }
        return sum - minx*nums.size();
    }
};