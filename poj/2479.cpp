#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 100005
int a[MAXN] = {0};
int dpl[MAXN] = {0};
int dpr[MAXN] = {0};
int T;


int main(int argc, char const *argv[])
{
	// scanf("%d",&T);
	int n;
	while(true){
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0;i<n;++i) scanf("%d",&a[i]);

		int maxSum = 0x80000000, thisSum = 0;
		for (int i=0;i<n;++i){
			thisSum += a[i];
			if (maxSum<thisSum) maxSum = thisSum;
			if (thisSum<0) thisSum=0; 
			dpl[i] = maxSum;
		}
		maxSum = 0x80000000, thisSum = 0;
		for (int i=n-1;i>=0;--i){
			thisSum += a[i];
			if (maxSum<thisSum) maxSum=thisSum;
			if (thisSum<0) thisSum=0;
			dpr[i] = maxSum;
		}
		int ret = 0x80000000;
		for (int i=0;i<n-1;++i){
			ret = max(ret,dpl[i]+dpr[i+1]);
		}
		// ret = max(dpr[0],ret);
		printf("%d\n",ret);

	}
	return 0;
}