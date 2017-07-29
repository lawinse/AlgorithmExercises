class Solution {
public:
    bool isValid(string s) {
        char stack[5000];
        char ch;
        int cnt = 0;
        int slen = s.length();
        for (int i = 0 ; i < slen; ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack[cnt++] = s[i];
            else
            {
                ch = stack[--cnt];
                if (s[i] == ')' && ch != '(' || s[i] == '}' && ch != '{' || s[i] == ']' && ch != '[') return false;
            }
        }
        if (cnt == 0)return true;
        else return false;
    }
};