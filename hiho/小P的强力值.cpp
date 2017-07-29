// http://hihocoder.com/problemset/problem/1358

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int n,k;
int a[15],b[15];

struct Data
{
	int idx;
	int base;
	double delta;
	Data(int a, int b, double c){idx = a, base = b, delta = c;}
	bool operator < (const Data &obj) const {
		return delta < obj.delta;
	}
};
int main(int argc, char const *argv[])
{
	double ans = 0;
	priority_queue<Data> Q;

	scanf("%d%d",&n,&k);
	for (int i=0; i<k; ++i) {
		scanf("%d",&a[i]);
	}
	for (int i=0; i<k; ++i) {
		scanf("%d",&b[i]);
	}

	for (int i=0; i<k; ++i) {
		Q.push(Data(i,a[i],(1.0/b[i])*(log(a[i]+1)-log(a[i]))));
		ans += (1.0/b[i])*log(a[i]);
	}

	for (int i=0; i<n; ++i) {
		Data cur = Q.top(); Q.pop();
		ans += cur.delta;
		cur.base++;
		cur.delta = (1.0/b[cur.idx])*(log(cur.base+1)-log(cur.base));
		Q.push(cur);
	}
	printf("%.7lf\n", pow(2.718281828459,ans));
	
	return 0;
}