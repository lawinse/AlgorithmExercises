class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k<=1) return s.size();
        if (s.size() == 0) return 0;
        return dfs(s,k,0,s.size());
    }
    
    int dfs(string &s, int k, int beg, int end) {
        int cnt[26] = {0};
        for (int j=beg; j<end; ++j) cnt[s[j]-'a']++;
        int max_len = 0;
        for (int j=beg; j<end;) {
            while (j<end && cnt[s[j]-'a']<k) j++;
            if (j == end) break;
            int l = j;
            while(l<end&&cnt[s[l]-'a'] >= k)l++;
            if (j == beg && l == end) return end-beg;
            max_len = max(max_len, dfs(s,k,j,l));
            j=l;
        }
        return max_len;
    }
};