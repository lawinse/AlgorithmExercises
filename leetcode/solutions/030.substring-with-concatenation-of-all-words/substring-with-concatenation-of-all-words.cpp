#include <string>
class Solution {
public:
   vector<int> findSubstring(string s, vector<string>& words) {
    int wc = words.size();
    int wl = words[0].length();
    vector<int> res;
    multiset<string> theSet(words.begin(),words.end()), iniSet = theSet;
    multiset<string>::iterator it;
    for(int i = 0; i < wl; i++)
    {
        theSet = iniSet;
        int flag = i, j = i;
        while(j <= (int)s.length())
        {
            if(theSet.size() == 0) {res.push_back(flag); theSet.insert(s.substr(flag,wl)); flag += wl;}
            else if((it = theSet.find(s.substr(j,wl))) != theSet.end()) {theSet.erase(it); j+= wl;}
            else if((it = iniSet.find(s.substr(flag,wl))) != iniSet.end()) {theSet.insert(s.substr(flag,wl)); flag += wl;}
            else {flag += wl; j += wl;}
        }
    }
    return res;
}	
    
};