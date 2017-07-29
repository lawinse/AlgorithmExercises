class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int, int>pointer;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        data.clear();
        pointer.clear();
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (pointer.find(val) != pointer.end()) return false;
        pointer[val] = data.size();
        data.emplace_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto found = pointer.find(val);
        if (found == pointer.end()) return false;
        int idx = found->second;
        if (data.size() == 1) {
            data.pop_back();
        } else {
            int back = data.back();
            pointer[back] = idx;
            data[idx] = back;
            data.pop_back();
        }
        pointer.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data[rand()%data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */