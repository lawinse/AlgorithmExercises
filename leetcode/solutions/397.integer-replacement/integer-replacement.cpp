class Solution {
public:
    int integerReplacement(int n) {
        if (n==1) return 0;
        if (n%2==0) return integerReplacement(n/2)+1;
        if (n == INT_MAX) return 2+integerReplacement(INT_MAX/2+1);
        return 1+min(integerReplacement(n+1),integerReplacement(n-1));
    }
};