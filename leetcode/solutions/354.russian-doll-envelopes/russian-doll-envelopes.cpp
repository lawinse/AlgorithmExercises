class Solution {
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),cmp);
        vector<int> dp;
        for (auto ev : envelopes) {
            auto iter = lower_bound(dp.begin(),dp.end(),ev.second);
            if (iter == dp.end()) dp.push_back(ev.second);
            else if (*iter > ev.second) *iter = ev.second;
        }
        return dp.size();
    }
};