class Solution {
public:
    vector<string> ret;
    void dfs(const string &num, const int& target, string cur, int pos, long pv, long cv, char op) {
        if (pos == num.size()-1 && cv == target) {
            ret.push_back(cur);
            return;
        }
        string next = "";
        long now = 0;
        int lmax = (num[pos+1] == '0' ? min(pos+2,(int)num.length()) : num.size());
        for (int i=pos+1; i<lmax; ++i) {
            next += num[i];
            now = now*10+(num[i]-'0');
            dfs(num,target,cur+'+'+next,i,now,cv+now,'+');
            dfs(num,target,cur+'-'+next,i,now,cv-now,'-');
            dfs(num,target,cur+'*'+next,i,pv*now,(op == '-') ? cv+pv-pv*now : ((op == '+') ? cv-pv+pv*now : pv*now), op);
        }
        
    }
    vector<string> addOperators(string num, int target) {
        if (num.size() == 0) return ret;
        if (num.size() == 1) {
            if (stol(num) == target) ret.push_back(num);
            return ret;
        }
        string s = "";
        long cur = 0;
        int lmax = (num[0] == '0' ? 1 : num.size());
        for (int i=0; i<lmax; ++i) {
            s += num[i];
            cur = cur*10+(num[i]-'0');
            dfs(num,target,s,i,cur,cur,'#');
        }
        return ret;
    }
};