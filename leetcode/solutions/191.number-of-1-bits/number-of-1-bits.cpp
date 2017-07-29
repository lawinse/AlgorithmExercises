class Solution {
public:
    int hammingWeight(uint32_t x) {
        if (x == 0) return 0;
        int cnt = 0;
        while(x){cnt++,x = (x-1)&x;}
        return cnt;
        
    }
};