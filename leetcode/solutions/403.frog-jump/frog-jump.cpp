class Solution {
    struct pairhash {
    public:
        template<typename T, typename U>
        size_t operator() (const pair<T,U>&obj) const {
            size_t l = hash<T>()(obj.first);
            size_t r = hash<U>()(obj.second);
            return l + 0x9e3779b9 + (r<<6) + (r>>2);
        }
    };

public:
    unordered_map<int, bool> dp;

bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
    int key = pos | k << 11;

    if (dp.count(key) > 0)
        return dp[key];

    for (int i = pos + 1; i < stones.size(); i++) {
        int gap = stones[i] - stones[pos];
        if (gap < k - 1)
            continue;
        if (gap > k + 1)
            return dp[key] = false;
        if (canCross(stones, i, gap))
            return dp[key] = true;
    }

    return dp[key] = (pos == stones.size() - 1);
}
};