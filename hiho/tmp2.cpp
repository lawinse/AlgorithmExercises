#include <iostream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N;

int getPrime(int *p) {
	bool *notPrime = new bool[N+5];
	memset(notPrime, 0 ,sizeof(bool)*(N+5));
	p[0] = 1;
	int cnt = 0;
	int tmp;
	for (int i=2; i<=N; ++i) {
		if (!notPrime[i]) p[++cnt] = i;
		for (int j=1; j<=cnt; ++j){
			if ((tmp=p[j]*i) > N) break;
			notPrime[tmp] = 1;
			if (i%p[j] == 0) break;
		}
	}
	delete [] notPrime;
	return cnt;

}

void reverse(int a[], int low, int high) {
	int n = high - low + 1;
	for (int i=0; i<n/2; ++i) {
		swap(a[low + i], a[low+(n-1-i)]);
	}
}

void m (int a[], int low, int mid, int high) {
	int i = low, j = mid;
	while(i<j && j<high) {
		while(i < j && a[i] <= a[j]) i++;
		int k=j;
		while(a[k] < a[i] && k < high) {
			k++;
			// int tmp = a[j];
			// for (int k=j; k>i; --k) {
			// 	a[k] = a[k-1];
			// }
			// a[i] = tmp;
			// ++j;
		}
		reverse(a,j,k-1);
		reverse(a,i,j-1);
		reverse(a,i,k-1);
		i += k-j;
		j = k;
		
	}
}

void ms(int a[], int n) {
	if(n <= 1) return;
	for (int bulk = 1; bulk < n; bulk<<=1) {
		for (int left = 0, mid = left + bulk, right; mid < n; left = right, mid = left + bulk) {
			m(a, left, mid, right = min(n,mid+bulk));
		}
	}
}

string shortestPalindrome(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        if (revs == s) return s;
        cout << s << endl;
        
        vector<int> table(s.size()+1,0);
        int i=0, j=0;
        while (i<s.size()) {
            if (i==0) j=0;
            else j = table[i-1];
            cout << i << endl;
            while(j>0 && revs[i] != s[j]) j = table[j-1], cout << s[j] << " " << revs[i]<<endl;
            table[i] = j + (revs[i] == s[j]);
            ++i;
        }
        return revs + s.substr(table[s.size()-1]);
    }

// int main(int argc, char const *argv[])
// {
// 	// cin >> N;
// 	// int *p = new int [N+5];
// 	// int size = getPrime(p);
// 	// int left = 1;
// 	// int right = size;

// 	// while(left < right) {
// 	// 	int sum = p[left] + p[right];
// 	// 	if (sum == N) cout << p[left] << "+" << p[right] << endl, left++,right--;
// 	// 	else if (sum < N) left ++;
// 	// 	else right --;
// 	// }

// 	// delete []p;


// 	// return 0;
// 	// srand(time(0));
// 	// int a[500],b[500];
// 	// for (int i=0; i<500; ++i) b[i]=a[i] = rand()%500;
// 	// ms(a,500);
// 	// sort(b,b+500);
// 	// for (int i=0; i<500; ++i){
// 	// 	cout << a[i] << " ";
// 	// 	if (a[i] != b[i]) cout << "wrong" <<endl;
// 	// }
// 	shortestPalindrome("aacecaaa");


// }

#include <iostream>
using namespace std;

int main() {
	int n,s,L;
    cin >> n >> s >> L;
    int per = (L+1)/(s+1);
    if (per % 13 != 0) {
       	int num = n/per;
       	int rest = n%per;
        // cout << num << " " << rest <<endl;
        if (num == 0 && rest % 13 == 0) {
        	cout << 2 <<endl;
        	return 0
        }
        if (rest == 0 || rest % 13 != 0) {
        	cout << num + (rest > 0) << endl;
            return 0;
        } else {
            cout << num + ((per-1)%13==0) + 1 << endl;
            return 0;
        }    
    } else {
        per--;
    	int num = n/per;
        int rest = n%per;
        cout << num +(rest>0) <<endl;
        return 0;
    }
}