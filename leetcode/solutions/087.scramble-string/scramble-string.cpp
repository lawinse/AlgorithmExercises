class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1 == s2) return true;
        int *a = new int[26];
        memset(a,0,sizeof(int)*26);
        for (int i = 0; i < s1.length();++i){
            ++a[s1[i]-'a'];
            --a[s2[i]-'a'];
        }
        for (int i = 0; i<26; ++i){
            if (a[i] != 0){
                delete[]a;
                return false;
            }
        }
        delete [] a;
        bool f;
        for (int len1 = 1; len1 < s1.length(); ++len1){
            f = isScramble(s1.substr(0,len1),s2.substr(0,len1)) && isScramble(s1.substr(len1),s2.substr(len1));
            if (f) return true;
            f = isScramble(s1.substr(0,len1),s2.substr(s2.length()-len1,len1)) && isScramble(s1.substr(len1),s2.substr(0,s2.length()-len1));
            if (f) return true;
        }
        return false;
    }
};