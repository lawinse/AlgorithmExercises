class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret =  x^y;
        int cnt = 0;
        while (ret) {
            cnt++;
            ret &= (ret-1);
        }
        return cnt;
    }
};