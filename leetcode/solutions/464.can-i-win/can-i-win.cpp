class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger*(maxChoosableInteger+1)/2<desiredTotal)
            return false;
        if (maxChoosableInteger >= desiredTotal)
            return true;
        unordered_map<int,bool> state;
        return dfs(0,state,desiredTotal,maxChoosableInteger);
    }
    
    bool dfs(int choiceHash, unordered_map<int,bool> &st, int target, int maxInt) {
        if (st.count(choiceHash)) return st[choiceHash];
        if (maxInt >= target) return true;
        
        for (int i=1; i<=maxInt; ++i) {
            if (choiceHash & (1<<(i-1))) continue;
            int nextMaxInt;
            if (i != maxInt) nextMaxInt = maxInt;
            else {
                for (nextMaxInt = maxInt-1; nextMaxInt > 0 && choiceHash&(1<<(nextMaxInt-1))==0; --nextMaxInt);
            }
            if (!dfs(choiceHash|(1<<(i-1)), st, target-i, nextMaxInt)) {
                return st[choiceHash] = true;
            }
        }
        return st[choiceHash] = false;
    }
};