class Solution {
public:
    int findNthDigit(int n) {
        if (n<=9) return n;
        long long base = 9;int cnt=1;
        do {
            n-=base*cnt;
            base*=10;++cnt;
        }while(n>base*cnt);
        int num = (n-1)/cnt+base/9;
        // cout << num <<endl;
        int rest = (n-1)%cnt;
        num /= pow(10,cnt-rest-1);
        // cout << cnt <<endl;
        // cout << rest <<endl;
        // cout << num << endl;
        return num%10;
        
    }
};