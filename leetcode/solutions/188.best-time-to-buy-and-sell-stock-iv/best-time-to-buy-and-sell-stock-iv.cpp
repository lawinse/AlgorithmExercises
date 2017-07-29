class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
       const int N = prices.size();
       const int K = k;
       if (k == 0 || N < 2) return 0;
       
       int ret = 0;
       int cnt = 0;
       for (int i=1; i<N; ++i){
           if (prices[i] > prices[i-1]){
               ret += (prices[i] - prices[i-1]);
               ++cnt;
           }
       }
       if (k>=cnt) return ret;
       ret = 0;
      int **dp = new int *[k+1];
      for (int i = 0; i<=k ;++i){
          dp[i] = new int [N];
          memset(dp[i],0,sizeof(int)*N);
      }
        // int dp[K+1][N] = {0};
       for (int i=1; i<=k; ++i){
           int tmpMax = dp[i-1][0]-prices[0];
           for (int j = 1; j<N; ++j){
               dp[i][j] = max(dp[i][j-1],prices[j] + tmpMax);
               tmpMax = max(tmpMax,dp[i-1][j]-prices[j]);
           }
       }
       ret = dp[k][N-1];
    //   for (int i=0; i<N; ++i) delete [] dp[i];
    //   delete [] dp;
       return ret;
    }
};