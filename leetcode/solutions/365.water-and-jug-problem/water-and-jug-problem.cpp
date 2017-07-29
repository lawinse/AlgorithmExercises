class Solution {
public:
    int gcd(int m, int n) {
        return (n==0)?m:gcd(n,m%n);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z > x+y) return false;
        if (z == x || z == y || z == x+y) return true;
        if (x < y) swap(x,y);
        return z % gcd(x,y) == 0;
    }
};