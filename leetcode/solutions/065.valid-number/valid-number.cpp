class Solution {
public:
    void skip(string &s, int&i) {
        int len = s.size();
        while (i < len && s[i] == ' ') i++;
    }
    
    bool getNum(string &s, int &i, bool allowSign) {
        bool isNum = false;
        int len = s.size();
        if (i<len && s[i] == '+' || s[i] == '-') {
            if (allowSign) i++;
            else return false;
        }
        if (i<len && isdigit(s[i])) isNum = true;
        while(i<len && isdigit(s[i])) i++;
        return isNum;
        
    }

    bool isNumber(string s) {
        int len = s.size();
        if (len == 0) return false;
        int i=0;
        bool isNum;
        skip(s,i);
        
        isNum = getNum(s,i,true);
        if (i<len && s[i] == '.') {
            i++;
            isNum |= getNum(s,i,false);
        }
        
        if (i<len && s[i] == 'e') {
            i++;
            if (!getNum(s,i,true)) return false;
        }
        skip(s,i);
        return isNum && i==len;
    }
};