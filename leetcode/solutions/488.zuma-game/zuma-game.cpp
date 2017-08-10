class Solution {
public:
    int findMinStep(string board, string hand) {
        int hc[26] = {0};
        for (auto c:hand) hc[c-'A']++;
        auto ret = dfs(board+"#",hc);
        return ret<6?ret:-1;
    }
    string next(string s) {
        for (int i=0, j=0; j<s.size(); ++j) {
            if (s[i] == s[j]) continue;
            if (j-i >= 3) return next(s.substr(0,i) +s.substr(j));
            else i=j;
        }
        return s;
    }
    int dfs(string bd, int *hc) {
        bd = next(bd);
        if (bd == "#") return 0;
        int ret = 6, nd = 0;
        for (int i=0,j=0; j<bd.size(); ++j) {
            if (bd[i] == bd[j]) continue;
            nd = 3-(j-i);
            if (hc[bd[i]-'A']>=nd) {
                hc[bd[i]-'A'] -= nd;
                ret = min(ret, nd+dfs(bd.substr(0,i)+bd.substr(j),hc));
                hc[bd[i]-'A'] += nd;
            }
            i=j;
        }
        return ret;
    }
};