class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        if (s.size() == 0) return true;
        
        bool *dp = new bool[s.size()+1];
        memset(dp,0,sizeof(bool)*(s.size()+1));
        dp[0] = 1;
        
        for(int i=1; i<=s.size(); ++i) {
            for (int j=i-1; j>=0; --j) {
                if (dp[j]) {
                    string tmp = s.substr(j,i-j);
                    if (wordDict.find(tmp) != wordDict.end()){
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        bool res = dp[s.size()];
        delete [] dp;
        return res;
    }
};