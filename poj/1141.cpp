#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int dp[250][250] = {0};
int pos[250][250] = {0};
string strin;
#define INF 0x3f3f3f3f

void printans(int i, int j){
	if (i>j) return;
	else if (i == j){
		if (strin[i] == '(' || strin[i] == ')'){
			cout << "()";
		}else{
			cout << "[]";
		}
	}else if (pos[i][j] == -1){
		cout << strin[i];
		printans(i+1,j-1);
		cout << strin[j];
	}else {
		printans(i,pos[i][j]);
		printans(pos[i][j]+1,j);
	}
}

int main(int argc, char const *argv[])
{
	cin >> strin;
	int n = strin.length();
	int i,j,k;
	for (i=0;i<n;++i) dp[i][i] = 1, pos[i][i] = i;
	for (k=1;k<n;++k){
		for (i=0;i+k<n;++i){
			j = i+k;
			dp[i][j] = INF;
			if (strin[i]=='(' && strin[j] == ')' || strin[i] == '[' && strin[j] == ']'){
				dp[i][j] = dp[i+1][j-1];
				pos[i][j] = -1;
			}
			for (int m=i;m<j;++m){
				if (dp[i][j] > dp[i][m] + dp[m+1][j]){
					pos[i][j] = m;
					dp[i][j] = dp[i][m] + dp[m+1][j];
				}
			}
		}
	}
	printans(0,n-1);
	cout << endl;
	
	return 0;
}