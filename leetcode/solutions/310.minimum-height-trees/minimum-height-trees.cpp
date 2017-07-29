class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if (n==1) {ret.emplace_back(0); return ret;}
        vector<int>ind(n+1,0);
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e.first].emplace_back(e.second);
            graph[e.second].emplace_back(e.first);
            ind[e.first]++;
            ind[e.second]++;
        }
        queue<int> Q;
        for (int i=0; i<n; ++i) {
            if (ind[i] == 1) Q.push(i);
        }
        while(!Q.empty()) {
            int i=0;
            int size = Q.size();
            for (i=0; i<size; ++i) {
                int cur = Q.front();Q.pop();
                ind[cur]--;
                if (n<=2) ret.emplace_back(cur);
                for (auto it:graph[cur]){
                    ind[it]--;
                    if (ind[it] == 1) Q.push(it);
                }
            }
            n-=size;
            if (n<=2) break;
        }
        while(!Q.empty()) ret.emplace_back(Q.front()),Q.pop();
        
        return ret;
    }
};