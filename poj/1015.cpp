#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[25][805];
int path[25][805];
int sum[205],diff[205];

int n,m;


inline bool isok(int i, int j, int k){
	while(i>0&&path[i][j]!=k){
		j-=diff[path[i][j]];
		i--;
	}
	return i==0?true:false;
}

int main(int argc, char const *argv[])
{
	int T = 1;
	while(~scanf("%d%d",&n,&m)){
		if(!(n||m)) break;
		int i,j,k,a,b;
		for (i=1;i<=n;++i){
			scanf("%d%d",&a,&b);
			sum[i] = a+b;
			diff[i] = a-b;
		}
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		const int fix = m*20;

		dp[0][fix]=0;
		for (i=1;i<=m;++i){
			for (j=0;j<=2*fix;++j){
				if (dp[i-1][j]>=0){
					for (k=1;k<=n;++k){
						if (dp[i][j+diff[k]]<dp[i-1][j]+sum[k]){
							if (isok(i-1,j,k)){
								dp[i][j+diff[k]] = dp[i-1][j]+sum[k];
								path[i][j+diff[k]] = k;
							}
						}
					}
				}
			}
		}

		for (i=0;i<=fix;++i){
			if (dp[m][fix+i]>=0 || dp[m][fix-i]>=0) break;
		}

		int opt_diff = (dp[m][fix+i]>dp[m][fix-i])?fix+i:fix-i;
		int opt_p = (dp[m][opt_diff]+(opt_diff-fix))/2;
		int opt_d = (dp[m][opt_diff]-(opt_diff-fix))/2;
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",T++,opt_p,opt_d);
		int *ret = new int[m+1];
		for (i=0,j=opt_diff;i<m;++i){
			ret[i] = path[m-i][j];
			j-=diff[path[m-i][j]];
		}
		sort(ret,ret+m);
		for (i=0;i<m;++i) printf(" %d",ret[i]);
		printf("\n\n");
		delete []ret;
	}
	
	return 0;
}