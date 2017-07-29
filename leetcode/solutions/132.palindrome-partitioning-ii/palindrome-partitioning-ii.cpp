class Solution {
public:
    int minCut(string s) {
        const int n = s.size();
        if (n == 0) return 0;
        int mincut[n];
        for (int i=0; i<=n; ++i) {
            mincut[i] = i-1;
        }
        
        for (int mid = 0; mid < n; ++mid) {
            int scal;
            for (scal = 0; mid+scal+1<=n && mid-scal>=0 && s[mid+scal] == s[mid-scal]; ++scal) {
                mincut[mid+scal+1] = min(mincut[mid+scal+1], mincut[mid-scal]+1);
            }
            for (scal = 0; mid+scal+2<=n && mid-scal>=0 && s[mid+scal+1] == s[mid-scal]; ++scal) {
                mincut[mid+scal+2] = min(mincut[mid+scal+2], mincut[mid-scal]+1);
            }
            
        }
        return mincut[n];
    }
};