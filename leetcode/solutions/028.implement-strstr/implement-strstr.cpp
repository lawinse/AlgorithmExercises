class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length()<needle.length()) return -1;
        for(int i=0;i<haystack.length()-needle.length()+1;++i){
            bool flag=1;
			for(int j=0;j<needle.length();++j){
				if(haystack[i+j]!=needle[j]) {flag=0;break;}
			}
			if(flag) return i;
		}
		
		return -1;
    }
    
};