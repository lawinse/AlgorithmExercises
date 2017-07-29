// http://hihocoder.com/problemset/problem/1307
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;

int W,H,N;
struct Rad{
    int x,y,r;
    int note;
    int idx;
    Rad(int _x=0,int  _y=0, int _r=0, int i=0):x(_x),y(_y),r(_r),idx(i){
        note = 0;
        if (_y+r>=H) note = 1;
        if (_y-r<=0) {
            if (note == 1) note = 10;
            else note = -1;
        } 
    };
};

inline bool isCon(const Rad&a, const Rad&b){
    return ((LL)(a.y-b.y))*((LL)(a.y-b.y))+((LL)(a.x-b.x))*((LL)(a.x-b.x)) <= ((LL)(a.r+b.r))*((LL)(a.r+b.r));
}

bool con[1005][1005];
Rad rads[1005];
bool v[1005];


int main(){
    int T;
    scanf("%d",&T);
    while(T--) {
        queue<Rad> Q;
        memset(con,0,sizeof con);
        memset(v,0,sizeof v);
        int a,b,c;
        bool fail = false;
        scanf("%d%d%d",&W,&H,&N);
        for (int i=0; i<N; ++i){
            scanf("%d%d%d",&a,&b,&c);
            rads[i] = Rad(a,b,c,i);
            if (rads[i].note == -1) Q.push(rads[i]),v[i] = 1;
            else if (rads[i].note == 10) fail = true;
            if (!fail){
                for (int j=0; j<i; ++j) con[j][i] = con[i][j] = isCon(rads[i],rads[j]);
            }
        }
        if (fail){
            printf("NO\n");
            continue;
        } else {
            while(!Q.empty()) {
                Rad cur = Q.front();Q.pop();
                if (cur.note == 1) {
                    fail = true;
                    break;
                }
                for (int i=0; i<N; ++i) {
                    if (v[i] || !con[i][cur.idx]) continue;
                    v[i] = 1;
                    Q.push(rads[i]);
                }
            }
            printf("%s\n",fail?"NO":"YES");
        }
    }
}