class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
        });
        int ret = 0;
        for (int i=0,j=0; j<pairs.size(); ++j) {
            if (j==0 || pairs[j][0] > pairs[i][1]) {
                ++ret;
                i=j;
            }
        }
        return ret;
    }

};