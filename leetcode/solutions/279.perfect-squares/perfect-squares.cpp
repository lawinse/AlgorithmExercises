class Solution {
public:
    int numSquares(int n) {
        if (n<0) return 0;
        if (n == 0) return 1;
        vector<int> vi(n+1,0);
        queue<int> Q;
        
        for (int i=1; i*i <=n; ++i) {
            if (i*i == n) return 1; 
            vi[i*i] = 1;
            Q.push(i*i);
        }
        
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for (int i=1,tmp; (tmp = cur + i*i) <=n; ++i) {
                if (vi[tmp]) continue;
                if (tmp == n) return vi[cur] + 1;
                else vi[tmp] = vi[cur] + 1, Q.push(tmp);
            }
        }
        return 0;
    }
};