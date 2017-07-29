class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ret = 1;
        int start = 9;
        for (int i = 1; i<=n && i<10; ++i) {
            ret += start;
            start*=(10-i);
        }
        return ret;
    }
};