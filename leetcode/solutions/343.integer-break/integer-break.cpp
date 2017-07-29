class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        int numofthree = n/3;
        int rest = n%3;
        if (rest == 1) return (int)pow(3,numofthree-1)*4;
        else if (rest == 2) return (int)pow(3,numofthree)*2;
        else return pow(3,numofthree);
    }
};