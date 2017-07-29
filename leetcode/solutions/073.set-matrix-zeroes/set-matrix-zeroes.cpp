class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        unordered_set <int> rows,cols;
        for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] == 0) rows.insert(i),cols.insert(j);
        }
        
        unordered_set <int> :: iterator it;
        for (it = rows.begin(); it != rows.end(); ++it) 
            for (int j = 0; j < n ;++j) matrix[*it][j] = 0;
        for (it = cols.begin(); it != cols.end(); ++it)
            for (int i = 0; i < m ;++i) matrix[i][*it] = 0;
        return;
        
    }
};