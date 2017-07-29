#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int N;
int a[150][150] = {0};
int tempSum[150] = {0};
int tmpmax,ret;

int getMax() {
	int thisSum = 0,maxSum = 0x80000000; 
	for (int i=0;i<N;++i) {
		thisSum += tempSum[i];
		if (thisSum<0) thisSum = 0;
		if (thisSum>maxSum) maxSum = thisSum;
	}
	return maxSum;
}


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	ret = 0x80000000;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) 
			scanf("%d",&a[i][j]);
	for (int i=0;i<N;++i){
		memset(tempSum,0,sizeof tempSum);
		for (int j=i;j<N;++j){
			for (int k=0;k<N;++k){
				tempSum[k] += a[j][k];
			}

			tmpmax = getMax();
			ret = max(ret,tmpmax);

		}
	}
	printf("%d\n", ret);

	return 0;
}