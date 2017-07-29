class Solution {
public:
    // int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    //     if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    //     const int row = matrix.size(), col = matrix[0].size();
    //     int sum[row+1][col+1] = {0};
    //     for (int i=0; i<row; ++i)
    //     for (int j=0; j<col; ++j) {
    //         sum[i+1][j+1] = matrix[i][j] + sum[i+1][j] + sum[i][j+1]-sum[i][j];
    //     }
    //     int maxx = INT_MIN;
    //     for (int l=0; l<col; ++l) {
    //         // memset(tsum,0,sizeof(tsum));
    //         for (int r=l; r<col; ++r) {
    //             // for (int k=0; k<row; ++k) {
    //             //     tsum[k] += matrix[k][r];
    //             // }
    //             set<int>st;
    //             st.insert(0);
    //             int csum = 0;
    //             for (int i=1; i<=row; ++i) {
    //                 csum = sum[i][r+1] - sum[i][l];
    //                 set<int>::iterator it = st.lower_bound(csum-k);
    //                 if (it != st.end()) maxx = max(maxx,csum-*it);
    //                 if (maxx == k) return k;
    //                 st.insert(csum);
    //             }
    //         } 
    //     }
    //     return maxx <= -4000000 ? -1:maxx;
    // }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    if (matrix.empty() || matrix[0].empty()) return -1;
    const int rsz=matrix.size(),csz=matrix[0].size();
    // vector<vector<int>> ltSum(rsz+1,vector<int>(csz+1,0));
    int ltSum[rsz+1][csz+1];
    memset(ltSum,0,sizeof ltSum);
    for (int i=0;i<rsz;i++){
        for (int j=0;j<csz;j++){
            ltSum[i+1][j+1] = ltSum[i+1][j]+ltSum[i][j+1]-ltSum[i][j]+matrix[i][j];
        }
    }
    int res=INT_MIN;
    for (int i=0;i<csz;i++){
        for (int j=i;j<csz;j++){
            set<int> temp;
            temp.insert(0);
            for (int l=0;l<rsz;l++){
                int curSum = ltSum[l+1][j+1]-ltSum[l+1][i];
                set<int>::iterator it = temp.lower_bound(curSum-k);
                if (it != temp.end()) res = max(res, curSum-*it);
                temp.insert(curSum);
            }
        }
    }
    return res;
}
};