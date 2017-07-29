class Solution {
public:
    struct Node{
        int x; int y; int hei;
        Node(int _x, int _y, int _h):x(_x),y(_y),hei(_h){};
        bool operator < (const Node &obj) const {
            return hei > obj.hei;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int m = heightMap.size();
        if (m <= 2) return 0;
        const int n = heightMap[0].size();
        if (n <= 2) return 0;
        bool vi[m][n] = {0};
        memset(vi,0,sizeof vi);
        priority_queue<Node> Q;
        for (int i=0; i<n; ++i){
            vi[0][i] = vi[m-1][i] = 1;
            Q.push(Node(0,i,heightMap[0][i]));
            Q.push(Node(m-1,i,heightMap[m-1][i]));
        }
        
        for (int i=1; i<m-1; ++i){
            vi[i][0] = vi[i][n-1] = 1;
            Q.push(Node(i,0,heightMap[i][0]));
            Q.push(Node(i,n-1,heightMap[i][n-1]));
        }
        
        int ret = 0;
        
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        
        while(!Q.empty()) {
            Node cur = Q.top(); Q.pop();
            // cout << cur->x << " " << cur->y <<endl;
            for (int dir=0; dir<4; ++dir) {
                int nx = cur.x+dx[dir];
                int ny = cur.y+dy[dir];
                if (nx>=0 && nx<m && ny>=0 && ny<n && !vi[nx][ny]) {
                    if (heightMap[nx][ny] < cur.hei) {
                        // cout << ret << endl;
                        ret += (cur.hei - heightMap[nx][ny]);
                        // cout << nx << " " << ny <<endl;
                        
                        // heightMap[nx][ny] = cur.hei;
                    }
                    vi[nx][ny] = 1;
                    Q.push(Node(nx,ny,max(cur.hei, heightMap[nx][ny])));
                }
            }
            
        }
        return ret;
    }
};