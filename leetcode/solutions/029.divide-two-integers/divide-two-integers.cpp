typedef long long LL;
#include <cmath>
class Solution {
public:
    int divide(int dividend, int divisor) {
        LL a = abs(double(dividend));
        LL b = abs(double(divisor));
        LL ret = 0;
        while (a >= b)
        {
            LL tmp = b;
            for (int i = 0; a>=tmp; tmp <<= 1, ++i)
            {
                ret += 1<<i;
                a -= tmp;
            }
        }
        if (ret > 2147483647 &&  !((dividend ^ divisor)>>31)) return 2147483647;
        else return (dividend ^ divisor)>>31?-ret : ret;
    } 
};