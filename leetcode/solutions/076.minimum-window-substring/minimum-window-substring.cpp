class Solution {
public:
    string minWindow(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen == 0 || tlen ==0 || slen < tlen) return "";
        int beg=0,end=0;
        int minL = INT_MAX, retB,retE;
        int remaining = tlen;
        int cnt[256] = {0};
        
        for(int i=0; i<tlen;++i) cnt[t[i]]--;
        while(end<slen) {
            if (cnt[s[end]] < 0) remaining--;
            cnt[s[end]]++;
            while(remaining == 0) {
                if (cnt[s[beg]] <= 0) {
                    remaining ++ ;
                    if (end-beg<minL){
                        minL = end-beg;
                        retB = beg;
                        retE = end;
                    }
                }
                --cnt[s[beg++]];
            }
            // ++cnt[s[end++]];
            end++;
        }
        return ( minL > slen )? "" : s.substr(retB,retE-retB+1);
    }
};