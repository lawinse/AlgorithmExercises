class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int zeros[32] = {0}, ones[32]= {0};
        for (auto n:nums) {
            int j=1;
            
            for (int i=0; i<31; ++i){
                int ret = j&n;
                if (ret) ones[i]++;
                else zeros[i]++;
                j<<=1;
            }
        }
        int ans = 0;
        for (int i=0; i<32; ++i) ans += zeros[i] * ones[i];
        return ans;
    }
};