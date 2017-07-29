class Solution {
public:
    bool row[9][9]={}, col[9][9] = {}, block[9][9] = {};
    void solveSudoku(vector<vector<char>>& board) {

        for (int i=0; i<9 ;++i)
        for (int j=0; j<9; ++j){
            if (board[i][j] != '.'){
                row[i][board[i][j]-'1'] = 1;
                col[j][board[i][j]-'1'] = 1;
                block[i/3*3+j/3][board[i][j]-'1'] = 1;
            }
        }
        
        dfs(0,0,board);
    }
    
    bool dfs(int r, int c, vector< vector<char> > & board){
        if (c == 9) c = 0,++r;
        if (r == 9) return true;
        if (board[r][c] != '.') return dfs(r,c+1,board);
        for (int i=0; i<9; ++i){
            if (!row[r][i] && !col[c][i] && !block[r/3*3+c/3][i]){
                board[r][c] = '1'+i;
                row[r][i] = col[c][i] = block[r/3*3+c/3][i] = 1;
                if (dfs(r,c+1,board)) return true;
                else {
                    row[r][i] = col[c][i] = block[r/3*3+c/3][i] = 0;
                    board[r][c] = '.';
                }
            }
        }
        return false;
    }
};