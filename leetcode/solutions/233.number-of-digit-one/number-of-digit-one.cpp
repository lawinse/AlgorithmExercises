class Solution {
public:
    int countDigitOne(int n) {
        long long m = 1;
        int ret = 0;
        for(;m<=n;m*=10) {
            int a = n/m, b = n%m;
            ret += (a+8)/10*m + (a%10 == 1) * (b+1);
        }
        return ret;
    }
};