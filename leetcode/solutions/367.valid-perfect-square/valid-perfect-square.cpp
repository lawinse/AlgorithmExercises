class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        if (num < 0) return false;
        int r = min(num/2,65535), l=1;
        while(l<r){
           int mid = (l+r) / 2;
           if (mid*mid == num) return true;
           if (mid*mid<num) l = mid+1;
           else r = mid-1;
        }
        return  l*l == num || r*r == num;
    }
};