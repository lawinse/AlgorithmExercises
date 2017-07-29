// http://hihocoder.com/problemset/problem/1367
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 1e9+7;
typedef long long LL;

LL dp09[105][1005];
LL dp19[195][1005];
LL dp[105][10005];

LL tmp[10005];
LL tmp1[10005];

int bit09[105];
int bit19[105];

void init() {
	dp09[0][0] = dp19[0][0] = 1;
	for (int i=0; i<99; ++i)
		for (int j=0; j<10; ++j)
			for(int k=0; k<900; ++k) {
				dp09[i+1][k+j] = (dp09[i+1][k+j] + dp09[i][k])%MOD;
				if (j>0)dp19[i+1][k+j] = (dp19[i+1][k+j] + dp19[i][k])%MOD;
			}
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int len = s.length();
	while(s[len] != '=')len--;
	int num = 1;
	for (int i=len-1; i>=0; --i) {
		if (s[i] == '?') {
			if (i==0 || (i>0&&s[i-1]=='+')) {
				bit19[num]++;
			} else bit09[num]++;
			num++;
		}else if (s[i]=='+') num=1;
	}
	init();

	int tot_len = s.length();
	dp[tot_len][0]=1;
	int carrymax = 0;
	for (int i=1; s[tot_len-i]!='=';++i) {
		int max09 = bit09[i]*9;
		int max19 = bit19[i]*9;
		int pos = tot_len-i;
		memset(tmp,0,sizeof(tmp));
		memset(tmp1,0,sizeof(tmp1));
		for(int j=0; j<=max09; ++j)
			for (int k=0; k<=max19; ++k){
				tmp[j+k] = (tmp[j+k] + dp09[bit09[i]][j] * dp19[bit19[i]][k]) % MOD;
			}
		int max_num = max19 + max09;
		for (int k=0; k<=max_num; ++k)
			for (int j=0; j<=carrymax; ++j){
				tmp1[k+j] = (tmp1[k+j] + tmp[k]*dp[pos+1][j]) % MOD;
			}
		max_num += carrymax;
		for (int j=s[pos]-'0'; j<=max_num; j+=10)
			dp[pos][j/10] = tmp1[j];
		carrymax = max_num/10;
	}
	cout << dp[len+1][0] <<endl;

	return 0;
}