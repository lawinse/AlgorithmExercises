class LRUCache{
private:
struct Node{
    int key;
    int value;
};
typedef list<Node>::iterator ITER;
int cap;
list<Node> data;
unordered_map<int, ITER>mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
        data.clear();
        mp.clear();
    }
    
    int get(int key) {
        if (mp.find(key)!=mp.end()){
            ITER it = mp[key];
            Node newNode;
            newNode.key = key;
            newNode.value = it->value;
            data.erase(it);
            data.push_front(newNode);
            mp[key] = data.begin();
            return newNode.value;
        }
        return -1;
    }
    
    void set(int key, int value) {
        if (mp.find(key)!=mp.end()){
            ITER it = mp[key];
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            data.erase(it);
            data.push_front(newNode);
            mp[key] = data.begin();
        }else{
            if (mp.size() == cap){
                mp.erase(data.back().key);
                data.pop_back();
            }
            Node newNode;
            newNode.key = key;
            newNode.value = value;
            data.push_front(newNode);
            mp[key]=data.begin();
        }
    }
};