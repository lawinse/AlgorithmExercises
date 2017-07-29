#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int,int> machine;

#define len first
#define width second

machine M[5005];
bool vi[5005];
int T,N;

bool cmp(machine &a, machine &b){
	return a.len==b.len?a.width<b.width:a.len<b.len;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for (int i=0;i<N;++i){
			scanf("%d%d",&M[i].len,&M[i].width);
		}
		sort(M,M+N,cmp);
		memset(vi,0,sizeof(vi));

		int ret = 0;
		int preW = -1;
		// int lastStart = 0;

		for (int i=0;i<N;++i){
			if (vi[i]) continue;
			preW = M[i].width;
			vi[i] = 1;
			for (int j=i+1;j<N;++j)
				if (M[j].width>=preW && !vi[j]) preW = M[j].width,vi[j]=1;
			ret ++;

		}

		printf("%d\n",ret );


	}

	
	return 0;
}