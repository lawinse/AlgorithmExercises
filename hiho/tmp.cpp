#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long dX[] = {0, -1, 0, 1};
const long long dY[] = {-1, 0, 1, 0};
long long N, M, Q, K, A[1100], B[1100], X[40], Y[40];
bool markX[1100], markY[1100], markXY[100][100];
long long idX[1100], idY[1100], n, m, Xid[100], Yid[100];
long long D[100][100], E[100][100][4];
priority_queue< pair<long long, long long> > que;

pair<long long, long long> findLU(long long x, long long y)
{
    pair<long long, long long> ret = make_pair(-1, 0);
    for (; x > 0 && !markX[x]; x --) ret.second += A[x-1];
    for (; y > 0 && !markX[y]; y --) ret.second += B[y-1];
    if (idX[x] == 0 || idY[y] == 0) return ret;
    ret.first = idX[x] * 100 + idY[y];
    return ret;
}

pair<long long, long long> findLD(long long x, long long y)
{
    pair<long long, long long> ret = make_pair(-1, 0);
    for (; x > 0 && !markX[x]; x --) ret.second += A[x-1];
    for (; y <= m && !markX[y]; y ++) ret.second += B[y];
    if (idX[x] == 0 || idY[y] == 0) return ret;
    ret.first = idX[x] * 100 + idY[y];
    return ret;
}

pair<long long, long long> findRU(long long x, long long y)
{
    pair<long long, long long> ret = make_pair(-1, 0);
    for (; x <= n && !markX[x]; x ++) ret.second += A[x];
    for (; y > 0 && !markX[y]; y --) ret.second += B[y-1];
    if (idX[x] == 0 || idY[y] == 0) return ret;
    ret.first = idX[x] * 100 + idY[y];
    return ret;
}

pair<long long, long long> findRD(long long x, long long y)
{
    pair<long long, long long> ret = make_pair(-1, 0);
    for (; x <= n && !markX[x]; x ++) ret.second += A[x];
    for (; y <= m && !markX[y]; y ++) ret.second += B[y];
    if (idX[x] == 0 || idY[y] == 0) return ret;
    ret.first = idX[x] * 100 + idY[y];
    return ret;
}

void update(long long x, long long y, long long z)
{
    if (x < 1 || x > n || y < 1 || y > m || markXY[x][y]) return;
    if (z < D[x][y]) {
        D[x][y] = z;
        que.push(make_pair(-z, x*100+y));
        // prlong longf("%lld %lld %lld\n", x, y, z);
    }
}

int main(int argc, char *argv[]) {
    scanf("%lld%lld", &N, &M);
    for (long long i = 1; i < N; i ++) {
        scanf("%lld", &A[i]);
    }
    for (long long i = 1; i < M; i ++) {
        scanf("%lld", &B[i]);
    }
    scanf("%lld", &K);
    for (long long i = 0; i < K; i ++) {
        scanf("%lld%lld", &X[i], &Y[i]);
        for (long long j = -1; j <= 1; j ++) {
            markX[X[i] + j] = true;
            markY[Y[i] + j] = true;
        }
    }
    for (long long i = 1; i <= N; i ++)
    if (markX[i]) {
        idX[i] = ++ n;
        Xid[n] = i;
    }
    for (long long i = 1; i <= M; i ++)
    if (markY[i]) {
        idY[i] = ++ m;
        Yid[m] = i;
    }
    for (long long i = 0; i < K; i ++) {
        markXY[idX[X[i]]][idY[Y[i]]] = true;
    }
    for (long long i = 1; i <= n; i ++) {
        for (long long j = 1; j <= m; j ++) {
            if (j < m) {
                for (long long k = Yid[j]; k < Yid[j + 1]; k ++) {
                    E[i][j][2] += B[k];
                }
                E[i][j + 1][0] = E[i][j][2];
            }
            if (i < n) {
                for (long long k = Xid[i]; k < Xid[i + 1]; k ++) {
                    E[i][j][3] += A[k];
                }
                E[i + 1][j][1] = E[i][j][3];
            }
        }
    }
    scanf("%lld", &Q);
    while (Q --) {
        long long X0, Y0, X1, Y1;
        scanf("%lld%lld%lld%lld", &X0, &Y0, &X1, &Y1);
        memset(D, 0x3f, sizeof(D));
        pair<long long, long long> c;
        c = findLU(X0, Y0);
        if (c.first != -1) update(c.first/100, c.first%100, c.second);
        c = findLD(X0, Y0);
        if (c.first != -1) update(c.first/100, c.first%100, c.second);
        c = findRU(X0, Y0);
        if (c.first != -1) update(c.first/100, c.first%100, c.second);
        c = findRD(X0, Y0);
        if (c.first != -1) update(c.first/100, c.first%100, c.second);
        while (!que.empty()) {
            long long d = -que.top().first;
            long long x = que.top().second/100;
            long long y = que.top().second%100;
            que.pop();
            if (d != D[x][y]) continue;
            for (long long i = 0; i < 4; i ++) {
                update(x + dX[i], y + dY[i], d + E[x][y][i]);
            }
        }
        long long ret = pow(2,50);
        c = findLU(X1, Y1);
        if (c.first != -1) ret = min(ret, D[c.first/100][c.first%100]+c.second);
        c = findLD(X1, Y1);
        if (c.first != -1) ret = min(ret, D[c.first/100][c.first%100]+c.second);
        c = findRU(X1, Y1);
        if (c.first != -1) ret = min(ret, D[c.first/100][c.first%100]+c.second);
        c = findRD(X1, Y1);
        if (c.first != -1) ret = min(ret, D[c.first/100][c.first%100]+c.second);
        if (ret == (long long)pow(2,50)) ret = -1;
        if (findLU(X0, Y0).first == findLU(X1, Y1).first) {
            ret = 0;
            if (X0 > X1) swap(X0, X1);
            for (long long i = X0; i < X1; i ++) ret += A[i];
            if (Y0 > Y1) swap(Y0, Y1);
            for (long long i = Y0; i < Y1; i ++) ret += B[i];
        }
        printf("%lld\n", ret);
    }
    return 0;
}




void pushup(int rt) {
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}

void build(int l, int r, int rt) {
    if (l == r) scanf("%d")>..

    int m = (l+r)/2;
    ...
    pushup(rt);
}

void update(int p)

