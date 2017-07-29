class Solution {
public:
    int strongPasswordChecker(string s) {
        int len = s.size();
        if (len < 2) return 6-len;
        char c = s[0];
        bool hasUpper = isupper(c), hasDigit = isdigit(c), hasLower = islower(c);
        int rep = 1, change = 0;
        int del[3] = {0};
        
        for (int i=1; i<len; ++i) {
            if (c == s[i]) ++rep;
            else {
                change += rep/3;
                if (rep/3>0) del[rep%3]++;
                c = s[i];
                rep = 1;
                hasUpper = hasUpper || isupper(c);
                hasLower = hasLower || islower(c);
                hasDigit = hasDigit || isdigit(c);
            }
        }
        change += rep/3;
        if (rep/3>0) del[rep%3]++;
        
        int req = !hasUpper + !hasLower + !hasDigit;
        if (len > 20) {
            int delcnt = len-20;
            if (delcnt <= del[0]) change -= delcnt;
            else if (delcnt - del[0] <= 2*del[1]) change -= del[0] + (delcnt-del[0])/2;
            else change -= del[0] + del[1] + (delcnt - del[0] - 2*del[1])/3;
            return delcnt + max(req, change);
        } else {
            return max(6-len, max(req, change));
        }
    }
};
