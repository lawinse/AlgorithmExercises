#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 10000
int F[MAXN][MAXN];

int f(int n, int k) {
	if (F[n][k] != -1) return F[n][k];
	if (n == 0) return F[n][k] = 0;
	if (k == 1){
		return F[n][k] = n;
	}
	int ret = INT_MAX;
	for (int i=1; i<=n; ++i) {
		ret = min(ret, 1+max(f(n-i,k),f(i,k-1)));
	}
	return F[n][k] = min(ret,f(n,k-1));
}

int main() {
	while (1) {
		memset(F,-1,sizeof F);
		int N,K;
		cin >> N >> K;
		cout << f(N,K) << endl;
	}
}