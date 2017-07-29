class Solution {
public:
    int numTrees(int n) {
        if (n<=1) return 1;
        int *a = new int[n+1];
        memset(a,0,sizeof(int)*(n+1));
        a[1] = a[0] = 1;
        for (int i=2; i<=n; ++i){
            for (int j=0; j<=i-1; ++j){
                a[i] += a[i-j-1]*a[j];
            }
        }
        int ret = a[n];
        delete []a;
        return ret;
        
        
    }
};