class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> mp;
    vector<int> data;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(0));
        data.clear();
        mp.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool f;
        auto found = mp.find(val);
        if (found == mp.end()) {
            f = true;
            mp[val] = unordered_set<int>{data.size()};
            data.emplace_back(val);
        } else {
            f = false;
            mp[val].insert(data.size());
            data.emplace_back(val);
        }
        return f;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto found = mp.find(val);
        if (found == mp.end()) return false;
        int rmv_idx = *(((found)->second).begin());
        if (data.size() == 1) {
            mp.erase(val);
            data.pop_back();
        }else if (((found)->second).size() == 1) {
            int back = data.back();
            mp[back].erase(data.size()-1);
            mp[back].insert(rmv_idx);
            data[rmv_idx] = back;
            data.pop_back();
            mp.erase(val);
        }else {
            int back = data.back();
            mp[back].erase(data.size()-1);
            mp[back].insert(rmv_idx);
            data[rmv_idx] = back;
            data.pop_back();
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return data[rand()%data.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */