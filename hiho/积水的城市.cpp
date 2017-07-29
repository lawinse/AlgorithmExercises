#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;


int N,M;
int a[505];
int b[505];
int K;
int Q;
int bx,by,ex,ey;
bool block[505][505] = {0};
bool vi[505][505];
int dis[505][505];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

inline bool valid(int x, int y) {
    return x>=1 && x<=N && y>=1 && y<=M && !block[x][y];
}

int getdis(int x, int y, int i) {
    if (i == 0) return b[x];
    if (i == 1) return b[x-1];
    if (i == 2) return a[y];
    else return a[y-1];
}

int spfa() {
    memset(vi,0,sizeof(vi));
    memset(dis,-1,sizeof(dis));
    queue< pair<int,int> >Q;
    dis[bx][by] = 0;
    vi[bx][by] = 1;
    Q.push(make_pair(bx,by));
    while(!Q.empty()) {
        pair<int,int> cur = Q.front();Q.pop();
        vi[cur.first][cur.second] = 0;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.first+dx[dir];
            int ny = cur.second+dy[dir];
            if (!valid(nx,ny)) continue;
            int nd = dis[cur.first][cur.second] + getdis(cur.first,cur.second,dir);
            if (dis[nx][ny] == -1 || nd < dis[nx][ny]) {
                dis[nx][ny] = nd;
                if (vi[nx][ny]) continue;
                else Q.push(make_pair(nx,ny)),vi[nx][ny] = 1;
            }
        }
    }
    return dis[ex][ey];
}


int main() {
    scanf("%d%d",&N,&M);
    for (int i=1; i<N; ++i) scanf("%d",&b[i]);
    for (int i=1; i<M; ++i) scanf("%d",&a[i]);
    scanf("%d",&K);
    for (int i=0; i<K; ++i) {
        int x, y;
        scanf("%d%d",&x,&y);
        block[x][y] = true;
    }
    scanf("%d",&Q);

    while(Q--) {
        scanf("%d%d%d%d",&bx,&by,&ex,&ey);
        printf("%d\n",spfa());
    }
}