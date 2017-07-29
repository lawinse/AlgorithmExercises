#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
map<int, pair<int, LL> > dic;
vector<int> nums;
int N,M;

void simulation(int t, LL &x, int &y) {
	for (int i=0; i<t; ++i) {
		for(auto num:nums) {
			if (y==M) {
				x++;
				y = 0;
			}
			y++;
			if (y+num>M) {
				x++;
				y = 0;
			}
			y += num;
		}
	} 
}

int main(int argc, char const *argv[])
{
	cin >> N >> M;
	string str;
	while(cin >> str) nums.push_back(str.size());

	LL x = 1L;
	int y = -1;
	for (int i=1; i<=N; ++i) {
		simulation(1,x,y);
		if (dic.find(y) != dic.end()) {
			LL rest = (N-i)%(i-dic[y].first);
			x += (N-i)/(i-dic[y].first)*(x-dic[y].second);
			simulation(rest,x,y);
			break;
		} else {
			dic[y] = make_pair(i,x);
		}
	}

	cout << x << " " << y;
	return 0;
}