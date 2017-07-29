class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 0) return ret;
        string s = "";
        dfs(n,n,ret,s);
        
        return ret;
    }
    void dfs(int lnum, int rnum, vector<string>&ret, string s){
        if (lnum == 0 && rnum == 0){
            ret.push_back(s);
            return;
        }
        if (lnum > 0){
            dfs(lnum-1,rnum,ret,s+'(');
        }
        if (rnum > 0 && rnum > lnum){
            dfs(lnum,rnum-1,ret,s+')');
        }
    }
};