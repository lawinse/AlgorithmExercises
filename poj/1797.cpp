#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int p[1005];
int N,M,T;

int find(int a){
	return (p[a]<0)?a:p[a]=find(p[a]);
}

void Union(int a, int b){
	if (a != b){
		if (p[a]>p[b]) p[b]+=p[a],p[a]=b;
		else p[a]+=p[b],p[b]=a;
	}
}

struct edge
{
	int u,v,w;
	edge(int _u=0,int _v=0,int _w = 0){u=_u,v=_v,w=_w;}
	bool operator < (const edge &obj) const{
		return w<obj.w;
	}
};



int main(int argc, char const *argv[])
{
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		scanf("%d%d",&N,&M);
		memset(p,-1,sizeof(p));
		priority_queue<edge> Q;
		int a,b,c;
		for(int i=0;i<M;++i){
			scanf("%d%d%d",&a,&b,&c);
			Q.push(edge(a,b,c));
		}
		// sort(E,E+M);

		int ret = 0x7fffffff;

		for (int i=0;i<M;++i){
			edge cur = Q.top();Q.pop();
			a = cur.u;
			b = cur.v;
			if (find(a)!=find(b)){
				ret = min(ret,cur.w);
				Union(find(a),find(b));
			}

			if (find(1)==find(N)) break;

		}

		printf("Scenario #%d:\n%d\n\n",t,ret);
	}


	
	return 0;
}