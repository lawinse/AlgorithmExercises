#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

int a[500005];
int b[500005];
LL ans = 0;
int N;

void m(int l, int r, int mid){
	int i=l,j = mid+1;
	int cnt = 0;
	while(i<=mid && j<=r){
		if (a[i] <= a[j]){
			b[cnt++] = a[i++];
		}else{
			ans += (mid-i+1);
			b[cnt++] = a[j++];
		}
	}

	// while(i<=mid){
	// 	b[cnt++] = a[i++];
	// }
	if (i<=mid){
		memcpy(b+cnt,a+i,(mid-i+1)*sizeof(int));
		cnt += mid-i+1;
	}
	if (j<=r){
		memcpy(b+cnt,a+j,(r-j+1)*sizeof(int));
		cnt += r-j+1;
	}
	// while(j<=r){
	// 	b[cnt++] = a[j++];
	// }

	memcpy(a+l,b,cnt*sizeof(int));

}

void ms(int l, int r){
	if (l>=r) return;
	int mid = (l+r)/2;
	ms(l,mid);
	ms(mid+1,r);
	m(l,r,mid);

}

int main(int argc, char const *argv[])
{
	while(~scanf("%d",&N) && N){
		ans = 0;
		for (int i=0;i<N;++i) scanf("%d",&a[i]);
		ms(0,N-1);
		printf("%lld\n",ans );
	}
	
	return 0;
}