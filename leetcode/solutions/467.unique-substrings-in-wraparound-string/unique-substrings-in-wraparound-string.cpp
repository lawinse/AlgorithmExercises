class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() <= 1) return p.size();
        
        int maxlen[26] = {0};
        
        int cnt = 1;
        char fch = p[0];
        maxlen[fch-'a'] = 1;
        for (int i=1; i<p.size();++i) {

            if (p[i-1]+1 == p[i] || p[i-1] == 'z' && p[i] == 'a') {
                cnt++;
            } else {
                maxlen[fch-'a'] = max(maxlen[fch-'a'], cnt);
                fch = p[i];
                cnt = 1;
            }
        }
        maxlen[fch-'a'] = max(maxlen[fch-'a'], cnt);
        for (int i=0,j; i<26;) {
            int ml = maxlen[i]-1;
            for (j = (i+1)%26; ml>=1 && j!=i; j = (j+1)%26) {
                if (ml > maxlen[j]) {
                    maxlen[j] = ml;
                    ml--;
                } else {
                    break;
                }
            }
            if (j<i) break;
            else i=j;
        }
        int ans = 0;
        for (int i=0; i<26; ++i) ans += maxlen[i];
        return ans;
    }
};