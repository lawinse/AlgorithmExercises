#include <sstream>
#include <string>
class Solution {
public:
    string getNext(string &s) {
        stringstream ss;
        int cnt = 0;
        char ch = s[0];
        for (int i = 0 ; i <= s.length(); ++i){ //pay attention to <= not <
            if (ch == s[i]){
                cnt ++;
            }else {
                ss << cnt << ch;
                cnt = 1;
                ch = s[i];
            }
        }
        return ss.str();
    }
    string countAndSay(int n) {
        string init = "1";
        if (n==1) return init;
        for (int i = 1; i < n; ++i){
            init = getNext(init);
        }
        return init;
    }
};