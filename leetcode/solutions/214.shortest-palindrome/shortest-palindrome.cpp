class Solution {
public:
    string shortestPalindrome(string s) {
        const int len = s.size();
        string rs = s;
        reverse(rs.begin(), rs.end());
        if (rs == s)return s;
        int i=1,j=0;
        int table[len+1] = {0};
        while(i<len) {
            j = table[i-1];
            while(j>0 && rs[i] != s[j]) j = table[j-1];
            table[i] = j + (rs[i] == s[j]);
            ++i;
        }
        return rs + s.substr(table[len-1]);
    }
};