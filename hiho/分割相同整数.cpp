//http://hihocoder.com/problemset/problem/1356
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
using namespace std;
int N;
int a[100005];
map<int, int> cnt;
set<pair<int,int> >heap;
#define MP(a,b) make_pair((a),(b))

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for (int i=0; i<N; ++i) {
		scanf("%d",&a[i]);
		++cnt[a[i]];
	}
	for (auto it:cnt) {
		heap.insert(MP(it.second, it.first));
	}
	if (heap.rbegin()->first * 2 - 1 > N) {
		printf("-1\n");
		return 0;
	}
	int pre = -1;
	for (int i=0; i<N; ++i) {
		int sel;
		if (heap.rbegin()->first*2-1 == (N-i)) {
			sel = heap.rbegin()->second;
		} else {
			for (auto it:cnt) {
				if (it.first != pre) {
					sel = it.first;
					break;
				}
			}
		}
		heap.erase(MP(cnt[sel],sel));
		if (--cnt[sel]>0){
			heap.insert(MP(cnt[sel],sel));
		} else {
			cnt.erase(sel);
		}
		printf("%d%c",sel," \n"[i==N-1] );
		pre = sel;
	}

	return 0;
}