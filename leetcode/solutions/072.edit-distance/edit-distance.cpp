class Solution {
public:
    int **dp;
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        if (len1*len2 == 0) return len2|len1;
        
        dp = new int *[len1+1];
        for (int i = 0; i <=len1; ++i){
            dp[i] = new int[len2+1];
            memset(dp[i],0,sizeof (int)*(len2+1));
            dp[i][0] = i;
        }
        for (int j=0; j <= len2; ++j){
            dp[0][j] = j;
        }
        
        char chi,chj;
        
        for (int i = 1; i <= len1; ++i)
        for (int j = 1; j <= len2; ++j){
            chi = word1[i-1];chj = word2[j-1];
            if (chi == chj){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + 1;
            }
        }
        int ret = dp[len1][len2];
        for (int i = 0; i<=len1; ++i) delete [] dp[i];
        delete [] dp;
        return ret;
    }
};