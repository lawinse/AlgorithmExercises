class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        if (n<0) return ret;
        ret.push_back(0);
        for (int i=0; i<n; ++i) {
            int cnt = ret.size();
            while(cnt) {
                cnt--;
                ret.push_back(ret[cnt] + (1<<i));
            }
        }
        return ret;
    }
};