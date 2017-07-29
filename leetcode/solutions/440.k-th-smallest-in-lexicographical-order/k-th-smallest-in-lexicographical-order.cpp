typedef long long LL;
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while(k>0) {
            LL steps = calStps(n, (LL)cur, (LL)cur+1);
            if (steps <= k) {
                k-=steps;
                cur++;
            } else {
                k--;
                cur*=10;
            }
        }
        return cur;
    }
    LL calStps(int n, LL left, LL right) {
       LL cnt = 0;
       while(left <= n) {
           cnt += min((LL)n+1, right) - left;
           left *= 10;
           right *= 10;
       }
       return cnt;
    }
};