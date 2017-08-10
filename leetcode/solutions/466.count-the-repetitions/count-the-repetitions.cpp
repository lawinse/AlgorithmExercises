class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> rep(s2.size()+1,0);        
        vector<int> next(s2.size()+1,0);
        unordered_map<int,int> rec;
        
        int id = 0, cnt = 0;
        for (int i=1; i<=n1; ++i) {
            for (int k=0; k<s1.size();++k) {
                if (s1[k] == s2[id]) id++;
                if (id==s2.size()) id=0,cnt++;
            }
            rep[i] = cnt;
            next[i] = id;
            
            
            if (rec.count(id)) {
                int start = rec[id];
                return(\
                       rep[start] + \
                       (rep[i]-rep[start])*((n1-start)/(i-start)) + \
                       rep[start+(n1-start)%(i-start)]-rep[start]\
                       ) / n2;
                    
            } else {
                rec[id] = i;
            }
        }
        return rep[n1] / n2;
    }
};