#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool used[256] = {0};
        int ans = 0;
        int p1 = 0, p2 = 0;
        while(1)
        {
            if (p2 == s.length()) {
                ans = max(ans,p2-p1);
                break;
            }
            if (!used[s[p2]]) used[s[p2]] = 1, p2++;
            else 
            {
                ans = max(ans,p2-p1);
                while(used[s[p2]]) used[s[p1++]] = 0;
                
            }
        }
        return ans;
    }
};