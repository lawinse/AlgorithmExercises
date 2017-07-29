#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f
int e[105][105]={0};
int N;

void floyd(){
	for (int k=1;k<=N;++k)
		for (int i=1;i<=N;++i)
			for (int j=1;j<=N;++j)
			{
				if (e[i][k]+e[k][j] < e[i][j]) e[i][j] = e[i][k]+e[k][j];
			}
}


int main(int argc, char const *argv[])
{
	int d,a,b;
	while(~scanf("%d",&N) && N!=0){
		for (int i=1;i<=N;++i){
			for (int j=1;j<=N;++j) e[i][j]=((i==j)?0:INF);
			scanf("%d",&d);
			while(d--) scanf("%d%d",&a,&b), e[i][a] = b;
		}
		floyd();
		int ans = INF, sel = -1;
		for (int i=1;i<=N;++i){
			int tmp = 0;
			for (int j=1;j<=N;++j){
				if (e[i][j]>tmp) tmp = e[i][j];
			}
			if (ans>tmp){
				ans = tmp;
				sel = i;
			}
		}
		if (sel == -1) printf("disjoint\n");
		else printf("%d %d\n", sel,ans);
	}

			
	return 0;
}