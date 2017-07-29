// http://hihocoder.com/problemset/problem/1363
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-7;

double V[4000];
double mat[4000][40];
int a[100][100];
int b[100][100];
int H,W,D;

void Solve(int m, int n){  // O(mn^2)
	int k=0,i,j;
	for (j=0; j<n; ++j) {
		for (i=k; i<m; ++i) {
			if (fabs(mat[i][j]) > eps) break;
		}
		if (i == m) continue;

		for (int y=0; y<n; ++y) swap(mat[i][y], mat[k][y]);
		swap(V[i],V[k]);

		double tmp = mat[k][j];
		for (int y=j; y<n; ++y) mat[k][y] /= tmp;
		V[k] /= tmp;

		for (int x=0; x<m; ++x) {
			if (x == k) continue;
			if (fabs(mat[x][j]) > eps) {
				tmp = mat[x][j];
				for (int y=0; y<n; ++y) mat[x][y] -= tmp*mat[k][y];
				V[x] -= tmp*V[k];
			}
		}
		++k;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&H,&W,&D);
	for (int i=0; i<H; ++i)
		for (int j=0; j<W; ++j) scanf("%d",&a[i][j]);
	for (int i=0; i<H-D+1; ++i)
		for (int j=0; j<W-D+1; ++j) scanf("%d",&b[i][j]);
	int r = 0;
	for (int i=0; i<H-D+1; ++i)
		for (int j=0; j<W-D+1; ++j) {
			for (int x=0; x<D; ++x) 
				for (int y=0; y<D; ++y) {
					mat[r][x*D+y] = a[i+x][j+y];
				}
			V[r] = b[i][j];
			++r;
		}
	Solve(r, D*D);

	for (int i=0; i<D*D; ++i) {
		if (i%D != 0) printf(" ");
		if (V[i] > -eps) printf("%.0f",V[i]+eps);
		else printf("%.0f",V[i]-eps);
		if (i%D == D-1) printf("\n");
	}

	return 0;
}
