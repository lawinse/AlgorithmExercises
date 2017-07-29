#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool vi[70] = {0};
int stick[70] = {0};

int sum,num,L,N;

bool cmp(int &a, int &b){
	return a>b;
}

bool dfs(int curnum, int pos, int rest){
	if (curnum == num) return true;
	for (int i=pos+1;i<N;++i){
		if (vi[i]) continue;
		if (rest == stick[i]){
			vi[i] = 1;
			if (dfs(curnum+1,-1,L)) return true;
			vi[i] = 0;
			return false;
		}else if (rest > stick[i]){
			vi[i] = 1;
			if (dfs(curnum,pos+1,rest-stick[i])) return true;
			vi[i] = 0;
			if (rest == L) return false;
			while(i<N-1 && stick[i] == stick[i+1]) ++i;
		}
	}
	return false;
}


int main(int argc, char const *argv[])
{
	int i;
	while(~scanf("%d",&N) && N!=0){
		memset(vi,0,sizeof(vi));
		memset(stick,0,sizeof(stick));
		sum = num = L = 0;
		for (i=0;i<N;++i) scanf("%d",&stick[i]),sum+=stick[i];
		sort(stick,stick+N,cmp);

		for (L=stick[0];L<=sum;++L){
			if (!(sum%L)){
				num = sum/L;
				if (dfs(0,-1,L)){
					printf("%d\n",L);
					break;
				}
			}
		}


	}
	return 0;
}