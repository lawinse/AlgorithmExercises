class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0) return ret;
        vector<int> cur;
        cur.push_back(1);
        ret.push_back(cur);
        if (numRows == 1) return ret;
        
        for (int curRows = 2; curRows<=numRows; ++curRows){
            cur.clear();
            cur.push_back(1);
            for (int i=0; i<ret[curRows-2].size()-1; ++i){
                cur.push_back(ret[curRows-2][i]+ret[curRows-2][i+1]);
            }
            cur.push_back(1);
            ret.push_back(cur);
        }
        return ret;
    }
};