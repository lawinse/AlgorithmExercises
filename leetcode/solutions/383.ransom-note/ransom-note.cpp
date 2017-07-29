class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[27] = {0};
        for (auto chr : magazine) {
            a[chr-'a']++;
        }
        for(auto chr : ransomNote) {
            a[chr-'a']--;
            if (a[chr-'a'] < 0) return false;
        }
        return true;
    }
};