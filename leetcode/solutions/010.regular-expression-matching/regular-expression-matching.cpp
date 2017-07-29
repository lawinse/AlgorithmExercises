class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.size() == 0) return s.size() == 0;
        if ('*' == p[1]) {
            return isMatch(s,p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1),p);
        } else {
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1),p.substr(1));
        }
    }
};