class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
    string res = "";
    while (i < word1.length() || i < word2.length()) {
        if (i < word1.length()) res.push_back(word1[i]);
        if (i < word2.length()) res.push_back(word2[i]);
        i++;
    }
    return res;
    }
};