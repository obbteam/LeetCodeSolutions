class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> freq1(26,0);

        for (auto l : s) freq1[l - 'a']++;

        for (auto l : t) freq1[l-'a']--;

        for (auto i : freq1) {
            if (i > 0) return false;
        }

        return true;
    }
};