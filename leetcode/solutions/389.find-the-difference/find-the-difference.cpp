class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        for(auto chr:s+t){
            ret ^= chr;
        }
        return ret;
    }
};