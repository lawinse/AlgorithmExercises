class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> data;
        for (auto a:A) for (auto b:B) data[a+b]++;
        int ret = 0;
        for (auto c:C) for (auto d:D) {
            if (data.find(-(c+d)) != data.end()) ret += data[-(c+d)];
        }
        return ret;
    }
};