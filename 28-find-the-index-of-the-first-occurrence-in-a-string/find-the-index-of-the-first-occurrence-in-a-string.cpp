class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t pos = haystack.find(needle);
        if (pos != std::string::npos) {
            return pos; // Return the index of the first occurrence
        } else {
            return -1; // Return -1 if needle is not found
        }
    }
};