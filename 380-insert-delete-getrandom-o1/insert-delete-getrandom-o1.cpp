class RandomizedSet {
public:
    RandomizedSet() {
        set.reserve(2 * 100000);
    }
    
    bool insert(int val) {
        if (set.contains(val)) return false;
        set.insert(val);
        size++;
        return true;
    }
    
    bool remove(int val) {
        if (!set.contains(val)) return false;
        set.erase(val);
        size--;
        return true;
    }
    
    int getRandom() {
        auto it = set.begin();
        std::advance(it, rand() % size);
        return *it;
    }

    private:
    unordered_set<int> set;
    size_t size = 0;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */