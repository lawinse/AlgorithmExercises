class Solution {
public:
    long long  hash(string &ori){
        long long ahash = 0;
        int n = ori.length();
        for (int i = 0; i < n; ++i) ahash += (long long)(pow(2.718,ori[i]-'a'+n));
        //ahash *= n;
        return ahash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long ,multiset<string>> mp;
        for (int i = 0; i < strs.size(); ++i){
            mp[hash(strs[i])].insert(strs[i]);
        }
        vector<vector<string>> ret;
        unordered_map<long long,multiset<string>>::iterator it;
        for (it = mp.begin();it != mp.end(); ++it){
            ret.push_back(vector<string>((it->second).begin(),(it->second).end()));
        }
        return ret;
    }
};