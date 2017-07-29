class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        const int N = A.size();
        if (N <= 2) return 0;
        int ret = 0, tmp = 0;
        for (int i=2; i<N; ++i) {
            if (A[i-1]-A[i-2] == A[i]-A[i-1]) ret += ++tmp;
            else tmp = 0;
        }
        return ret;
    }
};