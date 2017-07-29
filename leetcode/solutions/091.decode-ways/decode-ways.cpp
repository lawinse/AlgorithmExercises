class Solution {
public:
    int ans[3];
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || n == 1 && s == "0") return 0;
        if (n == 1) return 1;
        ans[0]=(s[0]!='0');
        ans[1]=ans[0]*((s[1]!='0'))+((((s[0]=='1')
                            ||(s[0]=='2' && s[1]<='6'))?1:0));
        for (int i=2;i<n;++i){
            ans[i%3] = ans[(i-1)%3]*((s[i]!='0'))+ans[(i-2)%3]*(((s[i-1]=='1')
                            ||(s[i-1]=='2' && s[i]<='6'))?1:0); 
        }
        return ans[(n-1)%3];
        
    }
};