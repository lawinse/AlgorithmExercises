class Solution {
public:
    long long gcd(long long m, long long n){
        if (m<n)swap(m,n);
        return (m%n)?gcd(n,m%n):n;
    }
    string fractionToDecimal(int nu, int de) {
        stringstream ss;
        long long numerator = nu;
        long long denominator = de;
        if (numerator == 0) return "0";
        if (numerator>0&&denominator<0 || numerator<0 && denominator>0) ss << '-';
        numerator = fabs(numerator);
        denominator = fabs(denominator);
        string loopPart = "",unloopPart = "";
        if (numerator%denominator == 0) {
            ss<<numerator/denominator;
            return ss.str();
        }
        int GCD = gcd(numerator,denominator);
        numerator /= GCD, denominator /= GCD;
        long long intPart = numerator/denominator;
        long long Rest = numerator%denominator;
        ss<<intPart<<'.';
        
        vector<int> xiaoshu;
        vector<int> xiaoshuRest;
        bool endd = 1;
        while(1 && endd){
            
            int i;
            if (Rest == 0){
                for (i=0; i<xiaoshu.size(); ++i){
                        unloopPart+=('0'+xiaoshu[i]);
                    }
                break;
                }
            for (i=0;i<xiaoshuRest.size(); ++i){

                if (Rest == xiaoshuRest[i]){
                    for (int j=0; j<i; ++j){
                        unloopPart+=('0'+xiaoshu[j]);
                    }
                    for (int j=i; j<xiaoshu.size(); ++j){
                        loopPart +=('0'+xiaoshu[j]);
                    }
                    endd = 0;
                    break;
                } 
            }
            int curDig = Rest*10/denominator;
            xiaoshuRest.push_back(Rest);
            xiaoshu.push_back(curDig);
            Rest = (Rest*10)%denominator;
        }
        if (loopPart.length()>0){
             ss<<unloopPart<<'('<<loopPart<<')';
        }
        else ss << unloopPart;
        return ss.str();
    }
};