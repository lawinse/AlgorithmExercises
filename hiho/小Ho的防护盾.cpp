// http://hihocoder.com/problemset/problem/1357

#include <iostream>
#include <cstdio>
using namespace std;

int n,m,k;
int a[100005];
#define INF 0x3f3f3f

bool ok(int t) {
	int kk = k;
	int blood = m;
	for (int i=0; i<n; ++i) {
		blood = min(blood+t, m) - a[i];
		if (blood <= 0) {
			kk--;
			blood = m;
		}
		if (kk <= 0) return false;
	}
	return kk>0;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d%d%d",&n,&m,&k)) {
		for (int i=0; i<n; ++i) scanf("%d",&a[i]);
		int l = 1, r = INF;
		while(l<r) {
			int mid = (r-l)/2 + l;
			if (ok(mid)) r = mid;
			else l = mid+1;
		}
		if (r == INF) printf("-1\n");
		else printf("%d\n", l);
	}
	return 0;
}