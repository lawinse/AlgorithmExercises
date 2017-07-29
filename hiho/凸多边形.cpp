//http://hihocoder.com/problemset/problem/1360
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

inline double getArea(int x1, int y1, int x2, int y2, int x3, int y3) {
	return fabs(0.5*(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1));
}

int x[105],y[105];
double area[105][105][105];
double dp[105][105][105];
int main(int argc, char const *argv[])
{
	int N,M;
	scanf("%d%d",&N,&M);
	for (int i=0; i<N; ++i) scanf("%d%d",&x[i],&y[i]);

	for (int i=0; i<N; ++i)
	for (int j=0; j<N; ++j)
	for (int k=0; k<N; ++k)
		area[i][j][k] = getArea(x[i],y[i],x[j],y[j],x[k],y[k]),dp[i][j][k] = 0;
	for (int dim = 3; dim<=M; ++dim) {
		for (int beg = 0; beg < N; ++beg) {
			for (int endd = beg+1; endd != beg; endd = (endd+1)%N) {
				for (int mid = beg+1; mid != endd; mid = (mid+1)%N) {
					dp[beg][endd][dim] = fmax(dp[beg][endd][dim], dp[beg][mid][dim-1] + area[beg][endd][mid]);
				}
			}
		}
	}
	double ret = 0;
	for (int i=0; i<N; ++i)
		for (int j=0; j<N; ++j)
			ret = fmax(ret,dp[i][j][M]);
	printf("%.2lf\n", ret);

	return 0;
}