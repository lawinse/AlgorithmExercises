class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen < tlen) return 0;
        vector<vector<int>> pos(256);
        vector<int> cnt(tlen);
        
        for(int i=tlen-1; i>=0; --i) pos[t[i]].push_back(i);
        
        for (int i=0; i<slen; ++i) {
            for (int j=0; j<pos[s[i]].size(); ++j) {
                int pos_cur = pos[s[i]][j];
                if (pos_cur == 0) cnt[0]++;
                else cnt[pos_cur] += cnt[pos_cur-1];
            }
        }
        return cnt[tlen-1];
        
    }
};