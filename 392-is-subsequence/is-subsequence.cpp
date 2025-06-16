class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto first = s.begin();
        auto second = t.begin();
        int count = 0;
        while (first != s.end() && second != t.end()) {
            if (*first != *second)
                second++;
            else {
                first++;
                second++;
                count++;
            }
        }
        return count == s.length();
    }
};