class Solution {
public:
    bool* vi;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();
        int tot = m*n;
        vi = new bool [m*n+5];
        memset(vi,0,sizeof(bool) * (m*n+4));
        int step = 0;
        
        if (n == 0) return ret;
        ret.push_back(matrix[0][0]);
        vi[0] = 1;
        int cx=0,cy=0;
        while(ret.size() != tot)
        {
            int dir = step%4;
            while(!vi[(cx+dx[dir])*n+cy+dy[dir]] && cx+dx[dir] >=0 &&cx+dx[dir]<m &&cy+dy[dir] >=0 && cy+dy[dir]<n)
            {
                ret.push_back(matrix[cx+=dx[dir]][cy+=dy[dir]]);
                vi[cx*n+cy] =1;
                if (ret.size() == tot) break;
            }
            step++;
        }
        return ret;
    }
};