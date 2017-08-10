struct Node;
Node *pool[54000][26];
struct Node {
        Node** childs;
        bool isEnd;
        Node(int id) {memset(pool[id],0,sizeof(pool[id]));childs=pool[id]; isEnd = false;}
    };

class Trie { // I dont know the reason why it should use class Trie other than just simple methods outside. But if i dont
            // do so, there would be always RE.
public:
    int ttl=0;
    Node *root = nullptr;
    
    Trie(){root = new Node(ttl++);}
    
    void addWord(string &w, Node * root) {
        Node* cur = root;
        for (auto c:w) {
            if (!(cur->childs[c-'a'])) {
                cur->childs[c-'a'] = new Node(ttl++);
            }
            cur = cur->childs[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool searchWord(string &w, int id, int cnt, Node *root) {
        int len = w.size();
        Node* cur = root;
        for (int i=id; i<len; ++i) {
            char ch = w[i];
            if (!(cur->childs[ch-'a'])) return false;
            if (cur->childs[ch-'a']->isEnd) {
                if (i == len-1) return cnt>=1;
                else if (searchWord(w, i+1, cnt+1, root)) return true;
            }
            cur = cur->childs[ch-'a'];
        }
        return false;
        
    }
    
};


class Solution {
public:
    vector<string> ret;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() == 0) return ret;
        
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        Trie trie;
        for(auto& w: words) {
            if (w.size() == 0) continue;
            if(trie.searchWord(w,0,0,trie.root)) ret.push_back(w);
            else trie.addWord(w,trie.root);
        }
        return ret;
    }
};