class Solution {
public:
    bool vi[500][500];
    int rows, cols;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    bool mySearch(vector<vector<char>>& board, int curX, int curY, int id, int remaining, string &word){
        int nowX,nowY;
        bool f = 0;
        if (remaining == 0) return true;
        for (int ii = 0; ii < 4; ++ii){
            nowX = curX+dx[ii];
            nowY = curY+dy[ii];
            if (nowX < rows && nowX >= 0 && nowY < cols && nowY >= 0 && board[nowX][nowY] == word[id+1] && !vi[nowX][nowY]){
                vi[nowX][nowY] = 1;
                f = mySearch(board,nowX,nowY,id+1,remaining-1,word);
                if (f) return true;
                vi[nowX][nowY] = 0;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = word.length();
        if (n == 0) return true;
        rows = board.size();
        if (rows == 0) return false;
        cols = board[0].size();
        if (cols == 0) return false;
        
        
        for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j){
            if (board[i][j] == word[0]){
                memset(vi,0,sizeof(vi));
                vi[i][j] = 1;
                if (mySearch(board,i,j,0,n-1,word)) return true;
            }
        }
        return false;
    }
};