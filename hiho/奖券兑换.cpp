// http://hihocoder.com/problemset/problem/1364
// 多重背包

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int cnt[15][15] = {0};
int f[100005] = {0};
int N,M;

void DP(int w, int p, int cnt) {
	int cur = 1;
	while(cnt >= cur) {
		int ww = cur*w;
		int pp = cur*p;
		for (int i=M; i>=ww; i--){
			f[i] = max(f[i],f[i-ww]+pp);
		}
		cnt -= cur;
		cur *= 2;
	}
	int ww = cnt*w;
	int pp = cnt*p;
	for (int i=M; i>=ww; i--){
		f[i] = max(f[i],f[i-ww]+pp);
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	int w,p;
	for (int i=0; i<N; ++i) {
		scanf("%d%d",&w,&p);
		++cnt[w][p];
	}
	for (int ww = 1; ww <=10; ++ww) 
		for (int pp = 1; pp<=10; ++pp) {
			if (cnt[ww][pp] > 0)DP(ww, pp, cnt[ww][pp]);
		}
	int ans = 0;
	for (int i=0; i<=M; ++i) ans = max(f[i],ans);
	printf("%d",ans);
	return 0;
}