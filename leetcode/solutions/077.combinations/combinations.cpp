class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> p(k,0);
        int i=0;
        while(i>=0) {
            p[i]++;
            if (p[i] > n) --i;
            else if (i == k-1) {
                ret.push_back(p);
            } else {
                ++i;
                p[i] = p[i-1];
            }
        }
        return ret;
    }
};