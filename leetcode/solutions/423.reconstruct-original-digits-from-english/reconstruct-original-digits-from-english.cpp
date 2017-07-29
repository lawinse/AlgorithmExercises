class Solution {
public:
    string originalDigits(string s) {
        string words[10] = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        char nums[10] = {'0', '2', '4', '6', '8', '1', '3', '5' ,'7', '9'};
        char distinct_char[10] = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        int cnt[26] = {0};
        int retcnt[10] = {0};
        string ret = "";
        for (auto c:s) cnt[c-'a']++;
        for (int i=0; i<10; ++i) {
            int count = cnt[distinct_char[i]-'a'];
            for (int j=0; j<words[i].size(); ++j) {
                cnt[words[i][j]-'a'] -= count;
            }
            retcnt[nums[i]-'0'] = count;
        }
        for (int i=0; i<10; ++i)
            for (int rep = 0; rep < retcnt[i]; ++rep)
                ret += to_string(i);
        return ret;
        
    }
};