#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int N,H;

int sumt[30] = {0};
int T[30][30] = {0};
struct pool
{	
	int id;
	int fishes;
	int dec;
	pool (int i = 0, int f = 0, int d = 0){id = i,fishes = f, dec = d;}
	bool operator < (const pool &obj) const{
		return (fishes == obj.fishes)?id>obj.id:fishes < obj.fishes;
	}
	
}F[30];

int main(int argc, char const *argv[])
{
	int i, j,tforfishing = 0;
	while(~scanf("%d",&N) && N){

		memset(T,0,sizeof(T));
		memset(sumt,0,sizeof(sumt));
		scanf("%d",&H);
		H *= 12;
		for (i=1;i<=N;++i){
			scanf("%d",&F[i].fishes);
			F[i].id = i;
		}
		for (i=1;i<=N;++i) scanf("%d",&F[i].dec);
		int t;
		for (i=1;i<=N-1;++i){
			scanf("%d",&t);
			sumt[i] = sumt[i-1]+t;
		}

		// Greedy

		int maxi, maxans = -1;

		for (i=1;i<=N;++i){
			int ans = 0;
			tforfishing = H - sumt[i-1];
			priority_queue<pool> Q;
			for (j=1;j<=i;++j) Q.push(F[j]);
			for (j=1;j<=tforfishing;++j){
				pool P = Q.top();Q.pop();
				ans += P.fishes;
				P.fishes = max(0,P.fishes-P.dec);
				T[i][P.id] += 5;
				Q.push(P);
			}
			if (maxans < ans) {
				maxi = i;
				maxans = ans;
			}
		}
		for (i=1;i<=N-1;++i) printf("%d, ",T[maxi][i] );
		printf("%d\n",T[maxi][N]);
		printf("Number of fish expected: %d\n\n", maxans);

	}
	
	return 0;
}