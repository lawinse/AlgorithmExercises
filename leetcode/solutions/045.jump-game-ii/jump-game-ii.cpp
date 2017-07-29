class Solution {
public:
    int jump(vector<int>&A) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = A.size();
        if (n <= 1)
            return 0;
        
        int minStep = 0;
        int maxLen = 0;
        int i = 0;
        while (i < n)
        {
            if (A[i] > 0)
                ++minStep;
            else
                return 0;
            // 当前所能达到的最远距离
            maxLen = A[i] + i;
            if (maxLen >= n-1)
                return minStep;
            int tmp = 0;
            // 下一步所能达到最远距离的起始坐标
            for (int j = i + 1; j <= maxLen; ++j)
            {
                if (tmp <= A[j] + j)
                {
                    tmp = A[j] + j;
                    i = j;
                }
            }
        }
        
        return minStep;
    }
};