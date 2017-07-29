pair <int, int>  stk[50000];
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int cnt = 0;
        int head = 0;

        int slen = s.length();
        for (int i = 0 ; i < slen; ++i){
            if (s[i] == '(') stk[cnt++] = make_pair(0,i+1);
            else {
                if (cnt == 0){
                    head = i+1;
                }
                else{
                    //pair<int,int> tmp = stk[--cnt];
                    --cnt;
                    if (cnt == 0){
                        ans = max(ans,i+1-head);
                    }
                    else{
                        ans = max(ans,i+1-stk[cnt-1].second);
                    }
                }
                
            }
        }
        return ans;
    }
};