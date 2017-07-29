class Solution {
private:
    vector< vector <string> > ret;
    string ss;
    int slen;
    void dfs(int start, vector<string>&vs){
        // const int slen = s.length();
        if (start == slen){
            ret.push_back(vs);
            return;
        }
        for (int i = start; i < slen; ++i){
            int l = start;
            int r = i;
            while(ss[l] == ss[r]) l++,r--;
            if(l>=r){
                vs.push_back(ss.substr(start,i-start+1));
                dfs(i+1,vs);
                vs.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        ss = s;
        slen = ss.length();
        vector<string>tmp;
        dfs(0,tmp);
        return ret;
    }
};