class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int len = s.size(), max_left = 0,max_len = 1,l,r;
        for (int start = 0; start < len && len-start>max_len/2;) {
            l = r = start;
            while(r < len-1 && s[r+1] == s[r]) ++r;
            start = r+1;
            while(r<len-1 && l>0&&s[r+1]==s[l-1]){
                ++r;
                --l;
            }
            if (max_len < r-l+1) {
                max_left = l;
                max_len = r-l+1;
            }
        }
        return s.substr(max_left,max_len);
    }
};