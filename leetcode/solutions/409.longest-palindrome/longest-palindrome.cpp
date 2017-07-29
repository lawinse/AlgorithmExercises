class Solution {
public:
    int longestPalindrome(string s) {
        int cnt[256] = {0};
        for (auto ch:s) {
            cnt[ch] += 1;
        }
        bool hasOdd = 0;
        int sum = 0;
        for (int i=0; i<256; ++i) {
            if (cnt[i]%2 == 0)sum += cnt[i];
            else hasOdd = 1, sum += cnt[i]-1;
        }
        sum += hasOdd;
        return sum;
    }
};