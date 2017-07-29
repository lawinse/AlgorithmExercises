class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k <= 0) return num;
        if (k >= num.size()) return "0";
        
        string ret = "";
        for (int i=0; i<num.size(); ++i) {
            while (!ret.empty() && ret.back() > num[i] && k) {
                k--;
                ret.pop_back();
            }
            if (!ret.empty() || num[i] != '0') ret.push_back(num[i]);
        }
        while (!ret.empty() && k) ret.pop_back(),k--;
        return ret.empty()?"0":ret;
    }
};