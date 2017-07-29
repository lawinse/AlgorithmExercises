class TrieNode {

public:
    // Initialize your data structure here.
       TrieNode* next[26];
        bool has;
        TrieNode(bool h=false){
            has = h;
            memset(next,0,sizeof(next));
        }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for(int i=0; i<word.size(); ++i){
            if (p->next[word[i]-'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->has = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode*p = root;
        for(int i=0; i<word.size(); ++i){
            if (p->next[word[i]-'a'] == NULL)
                return false;
            p = p->next[word[i]-'a'];
        }
        return p->has;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) {
        TrieNode*p = root;
        for(int i=0; i<word.size(); ++i){
            if (p->next[word[i]-'a'] == NULL)
                return false;
            p = p->next[word[i]-'a'];
        }
        return p!=NULL;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");