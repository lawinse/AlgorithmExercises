class Solution {
public:
    bool isSelfCrossing(vector<int> &x) {
        if (x.size() <= 3) return false;
        int i=2;
        for (;i<x.size() && x[i-2] < x[i]; ++i);
        if (i>2 && x[i]>=x[i-2]-((i==3)?0:x[i-4])) x[i-1] -= x[i-3];
        for (++i; i<x.size() && x[i-2] > x[i]; ++i);
        return i < x.size();
    }



    // bool isSelfCrossing(vector<int>& x) {
    //     if (x.empty()) return false;
    //     int i=2;
    //     for (;i<x.size() && x[i-2] < x[i]; ++i);
    //     // if (i == x.size()) return false;
    //     if (i>2 && x[i]>=x[i-2]-((i==3)?0:x[i-4])) x[i-1] -= x[i-3];
    //     for (++i;i<x.size() && x[i-2] > x[i]; ++i);
    //     return i < x.size();
    // }
};