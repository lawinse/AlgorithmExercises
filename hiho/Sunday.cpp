#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int Sunday(string s1, string s2) { // return -1 if not found.
	int len1 = s1.size();
	int len2 = s2.size();
	if (len1 < len2) return -1;
	int i=0, j=0;
	int pos[256];
	memset(pos,-1,sizeof pos);
	for (int i=0; i<len2; ++i) pos[s2[i]] = i;

	while(i<len1 && j<len2) {
		if (s1[i] == s2[j]) {
			++i;
			++j;
		} else {
			int pos1 = i + len2-j;
			int pos2 = pos[s1[pos1]];
			if (pos2 != -1) {
				i = pos1-pos2;
			} else {
				i = pos1 + 1;
			}
			j=0;
		}
	}

	if (i >= len1) return -1;
	else return i-len2;
}

int main(int argc, char const *argv[])
{
	while(1) {
		string s1;
		string s2;
		cin >> s1 >> s2;
		cout << Sunday(s1,s2) << endl;
	}
	return 0;
}