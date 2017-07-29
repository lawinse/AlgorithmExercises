class Solution {
public:
    bool isPowerOfFour(int num) {
        return num<0?false:((num-1)&num?false:num&0x555555555);
    }
};