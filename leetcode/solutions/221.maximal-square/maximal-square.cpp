class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int maxlen = 0;
        
        int **ret = new int *[m];
        for (int i=0; i<m;++i){
            ret[i] = new int [n];
            memset(ret[i],0,sizeof(int)*(n));
        }
        for (int i=0; i<m; ++i){
            ret[i][0] = matrix[i][0]-'0';
            maxlen = max(maxlen,ret[i][0]);
            for (int j=1;j<n; ++j){
                if (i == 0){
                    ret[i][j] = matrix[i][j]-'0';
                }else{
                    if (matrix[i][j]=='0') ret[i][j] = 0;
                    else{
                        ret[i][j] = min(min(ret[i-1][j],ret[i][j-1]),ret[i-1][j-1])+1;
                    }
                }
                maxlen = max(maxlen,ret[i][j]);
            }
        }
        return maxlen*maxlen;
    }
};