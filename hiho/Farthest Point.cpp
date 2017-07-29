// http://hihocoder.com/contest/hiho111/problem/1
#include <cstdio>
#include <cmath>
#include <algorithm>
const double eps = 1e-7;

double x,y,r;
double mindis = 0;
int retx, rety;
bool isBetter(double ax, double ay) {
	double dis_a = (ax-x)*(ax-x) + (ay-y)*(ay-y);
	if (fabs(dis_a-mindis) < eps) {
		if (ax == retx) {
			return (ay>rety);
		} else return ax>retx;
	}
	return dis_a > mindis + eps;
}

int main(int argc, char const *argv[])
{
	scanf("%lf%lf%lf",&x,&y,&r);

	for (int tx = ceil(x-r); tx <= floor(x+r); ++tx) {
		double d = sqrt(r*r-(tx-x)*(tx-x));
		int ty = ceil(y-d);
		if (isBetter(tx,ty)) {
			retx = tx;
			rety = ty;
			mindis = (tx-x)*(tx-x) + (ty-y)*(ty-y);
		}
		ty = floor(y+d);
		if (isBetter(tx,ty)) {
			retx = tx;
			rety = ty;
			mindis = (tx-x)*(tx-x) + (ty-y)*(ty-y);
		}
	}
	printf("%d %d\n", retx,rety);
	return 0;
}