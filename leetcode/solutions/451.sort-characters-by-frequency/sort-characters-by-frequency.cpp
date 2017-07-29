class Solution {
    
public:
    string frequencySort(string s) {
        vector<char>store;
        int num[256] = {0};
        for (auto c:s) {
            num[c]++;
            if (num[c] == 1) store.push_back(c);
        }
        auto cmp = [num](char a, char b) {
            return num[a] > num[b];
        };
        sort(store.begin(), store.end(), (cmp));
        string ret = "";
        for (auto c:store){
            for (int i=0; i<num[c]; ++i) ret += c;
        }
        return ret;
    }
};