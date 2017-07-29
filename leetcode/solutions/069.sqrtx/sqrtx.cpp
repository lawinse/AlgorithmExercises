class Solution {
public:
    int mySqrt(int x) {
        if (x<=1) return x;
        const int lim = sqrt(0x7fffffff);
        int l = 1, r = min(x/2+1,lim);
        int mid;
        while(l<r){
            mid = (l+r)/2;
            if (mid*mid<=x && (mid>=lim||(mid+1)*(mid+1)>x)) return mid;
            else if (mid*mid > x) r=mid;
            else l = mid+1;
        }
    }
};