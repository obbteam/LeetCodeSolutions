class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::unordered_map<int, int> freq;

        for (auto& x : arr) {
            freq[x]++;
        }

        unordered_set<int> s;
        for (auto& x : freq) {
            s.insert(x.second);
        }

        return s.size() == freq.size();
    }
};