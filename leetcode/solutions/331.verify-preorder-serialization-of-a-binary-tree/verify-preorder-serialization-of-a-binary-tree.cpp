class Solution {
public:
    bool isValidSerialization(string preorder) {
       istringstream iss(preorder);
       int nullCnt = 0, valCnt = 0;
       string tmp;
       while(getline(iss,tmp,',')){
           if (tmp == "#") nullCnt++;
           else valCnt++;
           if (iss.good() && nullCnt == valCnt + 1) return false;
       }
       return nullCnt == valCnt + 1;
    }
};