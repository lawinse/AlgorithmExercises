class Solution {
    const int MOD = 1337;
public:
    int quickPow(int a, int b) {
        a %= MOD;
        int ret = 1;
        while(b) {
            if (b & 1) ret = (ret*a)%MOD;
            a = (a*a)%MOD;
            b /= 2; 
        }
        return ret%MOD;
    }

    int superPow(int a, vector<int>& b) {
        if (b.size() == 0) return 0;
        if (b.size() == 1 && b[0] == 0) return 1; 
        a %= MOD;
        int store[10] = {0};
        store[0] = 1;
        for (int i=1; i<10; ++i) store[i] = (store[i-1]*a)%MOD;
        int ret = store[b[0]];
        
        for (int i=1; i<b.size(); ++i) {
            ret = quickPow(ret, 10);
            ret = (ret*store[b[i]])%MOD;
        }
        
        return ret%MOD;
    }
};