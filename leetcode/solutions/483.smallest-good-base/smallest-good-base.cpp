typedef unsigned long long ULL;
class Solution {
public:
    string smallestGoodBase(string n) {
        ULL n_ = (ULL)stoll(n);
        ULL a = 1;
        ULL ret;
        for (int i=63; i>=1; --i) {
            if ((a<<i)<n_) {
               if (ret=bs(n_,i)) return to_string(ret);
            }
        }
        return to_string(n_-1);
    }
    ULL bs(ULL n, ULL a) {
        ULL left = 1;
        ULL right = (ULL)(pow(n,1.0/a)+1);
        while (left <= right) {
            ULL mid = left + (right-left)/2;
            ULL sum=1, cur=1;
            for (int i=0; i<a; ++i) {
                cur*=mid;
                sum+=cur;
            }
            if (sum == n) return mid;
            else if (sum > n) right = mid-1;
            else left = mid+1;
        }
        return 0;
    }
};