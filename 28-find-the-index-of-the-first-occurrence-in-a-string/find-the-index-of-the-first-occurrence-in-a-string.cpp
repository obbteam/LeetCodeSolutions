class Solution {
public:
    int strStr(string haystack, string needle) {
        auto idx = haystack.find(needle);
        if (idx == string::npos) return -1;
        return idx;
    }
};