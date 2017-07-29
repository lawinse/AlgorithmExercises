class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        int count[26] = {0};
        int end = 0, start = 0;
        int maxCnt = 0, ret = 0;
        while(end < len) {
            maxCnt = max(maxCnt, ++count[s[end]-'A']);
            if (end-start+1-maxCnt > k) {
                count[s[start]-'A']--;
                start++;
            }
            ret = max(ret, end-start + 1);
            end++;
        }
        return ret;
    }
};