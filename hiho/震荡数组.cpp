// http://hihocoder.com/problemset/problem/1359

#include <cstdio>
#include <iostream>
using namespace std;

int n;
int a[110];
int ans = 0x3f3f3f3f;

inline bool ok(int idx) {
	if (idx == 1) return true;
	if ((idx%2)&&(a[idx]-a[idx-1]>0)) return true;
	if ((idx%2==0)&&(a[idx]-a[idx-1]<0)) return true;
	return false;
}

void dfs(int cur, int depth) {
	printf("cur = %d, a[cur] = %d, depth = %d\n",cur,a[cur],depth);
	if (cur == n+1) {
		ans = min(depth, ans);
		return;
	}
	if (depth >= ans) return;
	if (ok(cur)) dfs(cur+1,depth);

	if (depth+1>=ans) return;
	for (int i=cur+1; i<=n; ++i) {
		if (i!=1 && ok(i)) continue;
		swap(a[cur],a[i]);
		if (ok(cur)) {
			dfs(cur+1, depth+1);
		}
		swap(a[cur],a[i]);
	}


}

int main(int argc, char const *argv[])
{
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d",&a[i]);

	dfs(1,0);
	for (int i=1; i<=n; ++i) a[i] = -a[i];
	// dfs(1,0);
	printf("%d\n", ans);	

	return 0;
}