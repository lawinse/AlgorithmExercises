class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        for (auto num : nums) {
            times[num]++;
        }
        priority_queue< pair<int,int> > Q;
        for (auto pair = times.begin(); pair != times.end(); ++pair) {
            Q.push(make_pair((pair)->second, (pair)->first));
        }
        vector<int> ret;
        while(k--) {
            ret.push_back(Q.top().second);
            Q.pop();
        }
        return ret;
    }
};