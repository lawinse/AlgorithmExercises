class LFUCache {
    int cap;
    int size;
    int minf;
    unordered_map<int, pair<int,int>>k2vf;
    unordered_map<int, list<int>>freq2list;
    unordered_map<int, list<int>::iterator>kpos;
public:
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
        minf = 0;
    }
    
    int get(int key) {
        if (k2vf.find(key) == k2vf.end()) return -1;
        freq2list[k2vf[key].second].erase(kpos[key]);
        k2vf[key].second++;
        freq2list[k2vf[key].second].push_back(key);
        kpos[key] = --freq2list[k2vf[key].second].end();
        
        if (freq2list[minf].size() == 0) {
            ++minf;
        }
        return k2vf[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        
        int store = get(key);
        if (store != -1) {
            k2vf[key].first = value;
            return;
        }
        if (size >= cap) {
            k2vf.erase(freq2list[minf].front());
            kpos.erase(freq2list[minf].front());
            freq2list[minf].pop_front();
            size--;
        }
        freq2list[1].push_back(key);
        k2vf[key] = {value,1};
        kpos[key] = --freq2list[1].end();
        minf = 1;
        ++size;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */