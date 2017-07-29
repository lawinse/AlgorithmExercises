class Solution {
public:
    int reverse(int xx) {
        long long x = abs( (long long) xx); 
        long long p1 = 0, p2 = x;
        while(p2>0){
            p1 = p1*10+p2%10;
            p2 /=10;
        }
        if (xx>0){return p1 > 2147483647 ? 0 :p1;}
        else {return p1 > 2147483648 ? 0:-p1;}
    }
};