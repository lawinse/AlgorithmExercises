class Solution {
public:
string stk[1000];
    string simplifyPath(string path) {
        int beg,end;
        int n = path.length();
        beg = end = 1;
        string tmp;
        int ttl = 0;
        while(end <= n-1){
            while(end <= n-1 && path[end] != '/') end++;
            tmp = path.substr(beg,end-beg);
            //cout << tmp << endl;
            if (tmp == ".") ;
            else if (tmp == ".."){if (ttl)--ttl;}
            else if (tmp!="")stk[ttl++]=tmp;
            beg = end = end+1;
        }
        string ans = "";
        while(ttl>0){
            tmp = stk[--ttl];
            ans = "/" + tmp + ans;
        }
        if (ans == "") ans = "/";
        return ans;
    }
};