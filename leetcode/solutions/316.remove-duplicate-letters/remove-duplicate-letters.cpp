class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ret = "";
        int cnt[26] = {0};
        bool vi[26] = {0};
        int len = s.length();
        if (len < 2) return s;
        for (int i=0; i<len; ++i) cnt[s[i]-'a']++;
        
        for (int i=0; i<len; ++i) {
            int tmp = s[i]-'a';
            cnt[tmp]--;
            if (vi[tmp])continue;
            int j;
            for (j=ret.length()-1; j>=0; --j) {
                int tmp1 = ret[j]-'a';
                if (tmp1 > tmp && cnt[tmp1]) vi[tmp1] = 0;
                else break;
            }
            ret = ret.substr(0,j+1);
            ret += s[i];
            vi[tmp] = 1;
        }
        return ret;
    }
};

/*
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool visited[26] = {0};
        int len = s.length();
        for (int i=0; i<len; ++i) count[s[i]-'a']++;
        string ret = "";
        for (int i=0; i<len; ++i){
            int chr = s[i]-'a';
            count[chr]--;
            if (visited[chr]) continue;
            int j;
            for (j=ret.length()-1;j>=0;--j){
                int chrr = ret[j]-'a';
                if (chr<chrr && count[chrr]) visited[chrr] = false;
                else break;
            }
            ret = ret.substr(0,j+1);
            ret += s[i];
            visited[chr] = true;
        }
        return ret;
    }
};*/