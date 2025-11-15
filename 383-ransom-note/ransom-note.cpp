class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> freq;

        for (auto &c : magazine) freq[c]++;

        for (auto &c : ransomNote) {
            if (!freq.contains(c)) return false;
            freq[c]--;
            if (freq[c] < 0) return false;
        }

        return true;
    }
};