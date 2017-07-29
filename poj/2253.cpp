#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
double dis[205][205];
bool vi[205];
double a[205];

typedef pair<int,int> point;
#define x first
#define y second

point coord[205];

int N;

double getDis(int a, int b){
	return sqrt(double ((coord[a].x-coord[b].x)*(coord[a].x-coord[b].x)+(coord[a].y-coord[b].y)*(coord[a].y-coord[b].y)));
}

void spfa(){
	queue<int> Q;
	memset(vi,0,sizeof vi);
	vi[1] = 1;
	a[1] = 0;
	Q.push(1);
	while(!Q.empty()){
		int cur = Q.front();Q.pop();
		vi[cur] = 0;
		for (int i=1;i<=N;++i){
			if(cur == i) continue;
			if (a[i]>max(a[cur],dis[i][cur])){
				a[i] = max(a[cur],dis[i][cur]);
				if (vi[i]) continue;
				Q.push(i);
				vi[i] = 1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int T = 0;
	while(~scanf("%d",&N) && N){
		for (int i=1;i<=N;++i){
			scanf("%d%d",&coord[i].x,&coord[i].y);
		}
		T++;

		if (N == 2){
			printf("Scenario #%d\nFrog Distance = %.3f\n\n",T, getDis(1,2));
		}
		else{
			for (int i=1;i<=N;++i){
				a[i] = 1<<30;
				for (int j=1;j<=N;++j){
					if (i == j) dis[i][j] = 0;
					else dis[i][j] = dis[j][i] = getDis(i,j);
				}
			}
			// cout << a[1];
			spfa();
			printf("Scenario #%d\nFrog Distance = %.3f\n\n",T, a[2]);
		}

	}

	
}