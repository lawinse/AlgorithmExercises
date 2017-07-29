class Solution {
public:
    int fac[10] = {0,1,2,6,24,120,720,5040,40320,362880};
    bool*vi;
    string getPermutation(int n, int k) {
        string ret = "";
        k--;
        vi = new bool[n+1];
        memset(vi,0,sizeof (bool) * (n+1));
        int ch;
        int tmp;
        for (int i = n-1; i>=1  ;--i){
            tmp = k/fac[i]+1;
            ch = 1;
            while(tmp--){if(vi[ch])tmp++;ch++; }
            --ch;
            vi[ch] = 1;
            ret += (ch+'0');
            k%=fac[i];
        }
        for (int i = 1; i <=n; ++i) if (vi[i] == 0) ch = i;
        ret += ch+'0';
        return ret;
    }
    
};