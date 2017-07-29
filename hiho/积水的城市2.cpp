#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
const LL MAXLL = pow(2,50);
#define MP(a,b) make_pair((a),(b))

int N,M,K;
int A[1005] = {0};
int B[1005] = {0};
int cross[40][2] = {0};


map<int,int>xaxis,yaxis;
LL dis[105][105];
bool vi[105][105];
bool disca[105][105];
int row[105];
int col[105];
bool block[105][105] = {0};

inline bool valid(int x, int y, int n, int m) {
    return x>=1 && x<=n && y>=1 && y<=m && !block[x][y];
}


LL spfa(int xa, int ya, int xb, int yb){
    memset(vi,0,sizeof(vi));
    memset(disca,0,sizeof disca);
    int n = xaxis.size();
    int m = yaxis.size();
    queue<pair<int,int>>Q;
    Q.push(MP(xa,ya));
    dis[xa][ya] = 0;
    vi[xa][ya] = 1;
    LL curbest = MAXLL;
    while(!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        int x = cur.first, y = cur.second;
        vi[x][y] = 0;
        if (disca[x][y]) continue;
        if (x==xb && y==yb) curbest = min(curbest,dis[x][y]);
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x+dx[dir], ny = y+dy[dir];
            if (!valid(nx,ny,n,m)) continue;
            LL nd;
            switch(dir) {
                case 0: nd = dis[x][y] + row[nx+1]; break;
                case 1: nd = dis[x][y] + row[nx]; break;
                case 2: nd = dis[x][y] + col[ny+1]; break;
                case 3: nd = dis[x][y] + col[ny];break;
            }
            if (nd < dis[nx][ny]) {
                dis[nx][ny] = nd;
                if (vi[nx][ny]) continue;
                if (nd >= curbest) {disca[nx][ny] = 1; continue;}
                vi[nx][ny] = 1;
                Q.push(MP(nx,ny));
            }
        }
    }
    return dis[xb][yb] == MAXLL ? -1L : dis[xb][yb];

}

void addPoint(int point, map<int,int>& axis) {
    axis[point] = 1;
    axis[point+1] = 1;
}

void compress(map<int,int>& axis, int n, int* ori, int *len) {
    int cnt = 0;
    auto it = axis.begin();
    if (it->first != 1) axis[(it->first)-1] = 1;
    it = axis.end();
    it--;
    for (;it->first > n; axis.erase(it),--it);
    memset(len,0,sizeof(int)*105);
    for (it = axis.begin(); it != axis.end(); ++it) {
        it->second = ++cnt;
        if (cnt != 1) {
            auto pit = it;
            pit--;
            len[cnt] = ori[it->first] - ori[pit->first];
        }
    }
}

int main() {
    scanf("%d%d",&N,&M);
    for (int i=2; i<=N; ++i) scanf("%d",&B[i]), B[i] += B[i-1];
    for (int i=2; i<=M; ++i) scanf("%d",&A[i]), A[i] += A[i-1];
    scanf("%d",&K);
    for (int i=0; i<K; ++i) scanf("%d%d",&cross[i][0],&cross[i][1]);
    int Q,xa,ya,xb,yb;
    scanf("%d",&Q);

    while(Q--) {
        scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
        xaxis.clear();
        yaxis.clear();
        addPoint(xa,xaxis);
        addPoint(xb,xaxis);
        addPoint(ya,yaxis);
        addPoint(yb,yaxis);
        for (int i=0;i<K;++i) addPoint(cross[i][0],xaxis), addPoint(cross[i][1],yaxis);

        compress(xaxis,N,B,row);
        compress(yaxis,M,A,col);
        for (int i=0; i<105; ++i)
            for (int j=0; j<105; ++j) dis[i][j] = MAXLL;
        memset(block,0,sizeof(block));
        for (int i=0; i<K; ++i) block[xaxis[cross[i][0]]][yaxis[cross[i][1]]] = 1;
        printf("%lld\n",spfa(xaxis[xa],yaxis[ya],xaxis[xb],yaxis[yb]));

    }
}