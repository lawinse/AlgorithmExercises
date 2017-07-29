class Solution {
public:
    int rows, cols;
    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};
    void bfs(int x, int y, vector<vector<char>>& board){
        queue< pair<int,int> > Q;
        board[x][y] = 'F';
        Q.push(make_pair(x,y));
        pair<int,int> Cur;
        int cx,cy,nx,ny;
        while(!Q.empty()){
            Cur = Q.front(); Q.pop();
            cx = Cur.first, cy = Cur.second;
            for (int ii = 0; ii<4; ++ii){
                nx = cx+dx[ii],ny = cy+dy[ii];
                if (nx >= 0 && nx < rows && ny>=0 && ny <cols && board[nx][ny]=='O'){
                    board[nx][ny] = 'F';
                    Q.push(make_pair(nx,ny));
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if ((rows = board.size()) < 3) return;
        if ((cols = board[0].size()) < 3) return;
        
        for (int i=0; i<rows;++i){
            if (board[i][0] == 'O') bfs(i,0,board);
            if (board[i][cols-1] == 'O') bfs(i,cols-1,board);
        }
        for (int j=0; j<cols; ++j){
            if (board[0][j] == 'O') bfs(0,j,board);
            if (board[rows-1][j] == 'O') bfs(rows-1,j,board);
        }
        
        for (int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j)
            if (board[i][j] != 'X') board[i][j]+=9;
        }
        return;
    }
};