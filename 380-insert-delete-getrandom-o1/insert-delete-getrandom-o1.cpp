class RandomizedSet {
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (valuesIdx.contains(val)) return false;

        valuesIdx[val] = values.size();
        values.emplace_back(val);

        return true;
    }
    
    bool remove(int val) {
        if (!valuesIdx.contains(val)) return false;
        
        int idx = valuesIdx[val];
        valuesIdx[values.back()] = idx;
        valuesIdx.erase(val);
        values[idx] = values.back();
        values.pop_back();
        return true;
    }
    
    int getRandom() {
        return values[rand() % values.size()];
    }

    private:
    unordered_map<int, int> valuesIdx;
    vector<int> values;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */