class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1) return x;
        if (n == 0) return 1;
        double ans = 1;
        double tx =x;
        for (int t = abs(n); t != 0; t/=2)
        {
            if (t&1) ans *= tx;
            tx*=tx;
        }
        return n>0? ans : 1/ans;
    }
};