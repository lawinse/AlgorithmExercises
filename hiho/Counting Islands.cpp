//http://hihocoder.com/problemset/problem/1352?sid=853935
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000;
bool a[1005][1005] = {0};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
inline bool valid(int x, int y) {
    return x>=0 && x<MAXN && y>=0 && y<MAXN;
}

int father[1005*1000+1000];
int N;
int Find(int x) {
  return father[x]<0?x:father[x] = Find(father[x]);
}

void Union(int x, int y){
  if (x == y) return;
  else {
    if (father[x] > father[y]) {
      father[y] += father[x];
      father[x] = y;
    } else {
      father[x] += father[y];
      father[y] = x;
    }
  }
}

#define POS(i,j) (i)*1005+(j)
#define I(pos) (pos)/1005
#define J(pos) (pos)%1005

int main() {
    memset(father,-1,sizeof(father));
    scanf("%d",&N);
    int cnt = 0;
    for (int i=0; i<N; ++i) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
        cnt ++ ;
        for (int dir = 0; dir < 4; ++dir) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          if (!valid(nx,ny) || !a[nx][ny]) continue;
          if (Find(POS(x,y)) != Find(POS(nx,ny))) {
            Union(Find(POS(x,y)), Find(POS(nx,ny)));
            cnt--;
          }
        }
        printf("%d\n", cnt);

     }
}