class Solution {
public:
    unordered_map<string, int> parent;
    unordered_map<string, double> val;
    vector<vector<string>> child;
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int ttl = 1;
        child.push_back(vector<string>{});
        for (int i=0; i<equations.size(); ++i) {
            string a = equations[i].first; string b = equations[i].second;
            int fa = parent[a];
            int fb = parent[b];
            if (fa == 0 && fb == 0) {
                parent[a] = ttl;
                parent[b] = ttl++;
                val[b] = 1.0;
                val[a] = values[i];
                child.push_back(vector<string>{a,b});
            } else if (fb == 0) {
                parent[b] = fa;
                val[b] = val[a]/values[i];
                child[fa].push_back(b);
            } else if (fa == 0) {
                parent[a] = fb;
                val[a] = val[b]*values[i];
                child[fb].push_back(a);
            } else {
                double ratio = val[a]/values[i]/val[b];
                for (auto str : child[fb]) {
                    parent[str] = fa;
                    val[str] *= ratio;
                    child[fa].push_back(str);
                }
                child[fb].clear();
            }
        }
        
        vector<double>ret(queries.size());
        for (int i=0; i<queries.size(); ++i) {
            string a = queries[i].first; string b = queries[i].second;
            int fa = parent[a];
            int fb = parent[b];
            if (fa != 0 && fb != 0 && fa == fb) ret[i] = val[a]/val[b];
            else ret[i] = -1.0;
        }
        return ret;
    }
};