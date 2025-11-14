class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto c : s) {
            freq[c]++;
        }
        
        vector<pair<int, char>> v;
        for (auto &[c, f] : freq) {
            v.push_back({f, c});
        }

        sort(v.begin(), v.end(), [](const auto& a, const auto &b) {
            return a.first > b.first;
        });

        string ans;
        for(auto [freq, c] : v) {
            string toAdd(freq, c);
            ans += toAdd;
        }

        return ans;
    }
};