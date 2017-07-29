#include <cstdio>
#include <cstring>
using namespace std;
int N;
int map[30][30];
char s[80];
int color[30];
int ans;

bool isOK(int n) {
	// printf("isok(%d) ",n );
	for (int i=1;i<=map[n][0];++i) {
		// printf("%d ", i);
		if (color[map[n][i]] == color[n]) return false;
	}
	// printf("\n");
	return true;
}

bool dfs(int n) {
	if (n == N+1) {
		return true;
	}
	for (int i=1; i<=ans; ++i) {
		color[n] = i;
		if (isOK(n) && dfs(n+1)) return true;
		color[n] = 0; 
	}
	return false;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d",&N) && N) {
		memset(map,0,sizeof map);
		memset(color,0,sizeof color);
		for (int i=1; i<=N; ++i) {
			scanf("%s",s);
			map[s[0]-'A'+1][0] = strlen(s)-2;''
			for (int j=2;j<strlen(s);++j) {
				// printf("%d\n",s[j]-'A'+1);
				map[s[0]-'A'+1][j-1] = s[j]-'A'+1;
			}
		}
		// printf("%d %d %d\n", map[2][1], map[2][2], map[2][3]);
		for (ans = 1; ans<=N; ++ans) {
			if (dfs(1)) break;
		}
		if (ans == 1) printf("1 channel needed.\n");
		else printf("%d channels needed.\n", ans);

	}
	return 0;
}