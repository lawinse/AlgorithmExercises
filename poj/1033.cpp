#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int pos[10005] = {0};
int N,K;
stack<int> s;


int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&K);
	int cnt = 1,n,p;
	for (int i=0; i<K; ++i) {
		scanf("%d",&n);
		for (int j=0;j<n;++j) {
			scanf("%d",&p);
			pos[p] = cnt++;
		}
	}
	int nxt;
	bool f = false;
	for (int i=1; i<=N; ++i) {
		if (pos[i] == 0 || pos[i] == i){
			continue;
		}else{
			f = true;
			s.push(i);
			nxt = pos[i];
			bool loop = false;
			while(1) {
				if (pos[nxt] == 0) {
					loop = false;
					break;
				}else if (pos[nxt] == i) {
					loop = true;
					break;
				}
				s.push(nxt);
				nxt = pos[nxt];
			}
			int j;
			if (loop) {
				for (j=N; j>0 && pos[j]!=0; --j);
				printf("%d %d\n", nxt, j);
				pos[j] = pos[nxt];
				while(!s.empty()) {
					int tmp = s.top();s.pop();
					printf("%d %d\n", tmp,nxt);
					pos[nxt] = pos[tmp];
					nxt = tmp;
				}
				printf("%d %d\n", j, nxt);
				pos[nxt] = pos[j];
				pos[j] = 0;
			}else {
				while(!s.empty()) {
					int tmp = s.top();s.pop();
					printf("%d %d\n", tmp,nxt);
					pos[nxt] = pos[tmp];
					nxt = tmp;
				}
				pos[nxt] = 0;
			}
		}
	}
	if (!f) printf("No optimization needed\n");
	return 0;
}