class Solution {
public:
    bool closeStrings(std::string word1, std::string word2) {
        if (word1.size() != word2.size())
            return false;
        std::unordered_map<char, int> map1, map2;

        for (auto c : word1) {
            map1[c]++;
        }
        for (auto c : word2) {
            if (!map1.contains(c))
                return false;
            map2[c]++;
        }

        std::unordered_map<int, int> freqs;
    for (auto pair: map1) {
        freqs[pair.second]++;
    }

    for (auto pair: map2) {
        freqs[pair.second]--;
        if (freqs[pair.second] < 0) return false;
    }

    return true;
    }
};