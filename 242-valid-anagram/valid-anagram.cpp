class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freq1;

        for (auto l : s) freq1[l]++;

        for (auto l : t) {
            freq1[l]--;
            if (freq1[l] == 0) freq1.erase(l);
        }
        return freq1.empty();
    }
};