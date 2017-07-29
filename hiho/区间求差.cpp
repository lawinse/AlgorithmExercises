// http://hihocoder.com/problemset/problem/1305
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 100005
int M,N;

struct Point{
	bool isA;
	bool isStart;
	int value;
	bool operator < (const Point &obj) const {
		return value < obj.value;
	}
	Point(bool a=0, bool b=0, int c=0):isA(a),isStart(b),value(c){}
};

Point P[4*MAXN];


int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	int x,y;
	int cnt = 0;
	for (int i=0; i<N; ++i) {
		scanf("%d%d",&x,&y);
		P[cnt++] = Point(1,1,x);
		P[cnt++] = Point(1,0,y);
	}
	for (int i=0; i<M; ++i) {
		scanf("%d%d",&x,&y);
		P[cnt++] = Point(0,1,x);
		P[cnt++] = Point(0,0,y);
	}
	sort(P,P+cnt);
	int ret = 0;
	int s[2] = {0};
	for (int i=0; i<cnt; ++i) {
		if (i>0 && s[0] == 0 && s[1] > 0) ret += P[i].value-P[i-1].value;
		s[P[i].isA] += (P[i].isStart?1:-1);
	}
	printf("%d\n", ret);

	return 0;
}