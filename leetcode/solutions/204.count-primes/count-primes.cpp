class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        int *p = new int [n+1];
        bool *notPrime = new bool [n+1];
        memset(notPrime, 0, sizeof notPrime);
        int cnt = 0;
        p[0] = 1;
        int tmp;
        for (int i=2; i<n; ++i) {
            if (!notPrime[i]) p[++cnt] = i;
            for (int j=1; j<=cnt; ++j) {
                if ((tmp = p[j]*i) >= n) break;
                notPrime[tmp] = true;
                if (i%p[j] == 0) break;
            }
        }
        return cnt;
    }
};