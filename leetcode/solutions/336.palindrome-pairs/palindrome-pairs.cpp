struct Node {
        int idx;
        int p[26];
        Node() {
            clear();
        }
        void clear() {
            idx = -1;
            memset(p,-1,sizeof(p));
        }
    }N[100000];
class Solution {
public:

    
    int t = 1;
    
    void add(int id, const string &s) {
        int nxt = 0;
        for (int i=0; i<s.size(); ++i) {
            if (N[nxt].p[s[i]-'a'] == -1) {
                N[t].clear();
                N[nxt].p[s[i]-'a'] = t++;
            }
            nxt = N[nxt].p[s[i]-'a'];
        }
        N[nxt].idx = id;
    }
    
    int query(const string &s) {
        int nxt = 0;
        for (int i=0; i<s.size(); ++i) {
            if (N[nxt].p[s[i]-'a'] == -1) {
                return -1;
            }
            nxt = N[nxt].p[s[i]-'a'];
        }
        return N[nxt].idx;
    }
    
    
    bool isPali (string &s) {
        if (s.length() < 2) return true;
        for (int i=0; i<s.length()/2; ++i){
            if (s[i] != s[s.length()-1-i]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        t = 1;
        N[0].clear();
        for (int i=0; i<words.size(); ++i) add(i,words[i]);
        for (int i=0; i<words.size(); ++i) {
            string wd = words[i];
            reverse(wd.begin(),wd.end());
            int len = wd.length();
            for (int j=0; j<=len ;++j) {
                string lpart = wd.substr(0,j), rpart = wd.substr(j);
                int id;
                if (j < len && (id=query(lpart)) != -1 && id != i && isPali(rpart)) {
                    ret.push_back(vector<int>{id, i});
                }
                if ((id=query(rpart)) != -1 && id != i && isPali(lpart)) {
                    ret.push_back(vector<int>{i,id});
                }
            }
        }
        return ret;
    }
};