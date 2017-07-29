class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int curMin = prices[0];
        int ret = -1<<30;
        for (auto it = prices.begin();it!=prices.end(); ++it){
            curMin = min(curMin,*it);
            ret = max(ret,*it-curMin);
        }
        return ret;
    }
};