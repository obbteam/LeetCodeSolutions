class Solution {
public:
    bool isSubsequence(string& s, string& t) {
        auto first = s.begin();
        auto second = t.begin();
        int count = 0;
        while (first != s.end() && second != t.end()) {
            if (*first != *second)
                ++second;
            else {
                ++first;
                ++second;
                count++;
                if (count == s.length())
                    return true;
            }
        }
        return count == s.length();
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        std::unordered_map<string, bool> solutions;
        int count = 0;
        for (string& word : words) {
            if (!solutions.contains(word)) {
                solutions[word] = isSubsequence(word, s);
                count += solutions[word];
            } else {
                count += solutions[word];
            }
        }
        return count;
    }
};