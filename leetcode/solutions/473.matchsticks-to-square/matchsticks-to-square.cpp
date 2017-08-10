class Solution {
public:
    bool dfs(int len[], int target, int index, vector<int>&match) {
        if (index == match.size()) 
            return len[0] == len[1] && len[1] == len[2] && len[2] == len[3];
        for (int i=0; i<4; ++i) {
            if (len[i] + match[index] > target) continue;
            int j;
            for (j=i-1; j>=0; --j) {
                if (len[j] == len[i]) break;
            }
            if (j>=0) continue;
            len[i] += match[index];
            if (dfs(len, target, index+1, match)) return true;
            len[i] -= match[index];
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        long long sum = 0;
        for (auto a:nums) sum += a;
        if (sum % 4 != 0) return false;
        
        sort(nums.begin(), nums.end(),[](const int&l, const int &r){return l > r;});
        
        int len[4] = {0};
        return dfs(len, sum/4, 0, nums);
    }
    
};