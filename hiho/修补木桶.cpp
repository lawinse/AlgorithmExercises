//http://hihocoder.com/problemset/problem/1362
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int h[1005];
int b[1005];
int N,M,L;

bool isOK(int ans) {
	for (int st = 0; st < N; ++st) {
		if (h[st] >= ans) continue;
		int cur = st;
		for (int t = 0; t < M; ++t) {
			cur = (cur+L)%N;
			while (h[cur]>=ans && cur != st) cur = (cur+1)%N;
			if (cur == st) return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&M,&L);
	for (int i=0; i<N; ++i) scanf("%d",&h[i]), b[i] = h[i];
	sort(b,b+N);
	int l=0;
	int r=N;
	while(l<r-1) {
		int mid = (l+r)/2;
		if (isOK(b[mid])) l = mid;
		else r = mid;
	}
	printf("%d\n",b[l]);
	return 0;
}