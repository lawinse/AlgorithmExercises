class Solution {
typedef pair<int,int> PII;
    static bool cmp(const PII& a, const PII& b){
        return a.first < b.first;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int len = points.size();
        if (len < 2) return len;
        sort(points.begin(), points.end(),cmp);
        int ret = 0;
        int beg = -1, end = -1;
        for (auto p:points) {
            if (p.first > end) {
                ret ++;
                beg = p.first, end = p.second;
            } else {
                if (p.second < end) end = p.second;
            }
        }
        return ret;
    }
};