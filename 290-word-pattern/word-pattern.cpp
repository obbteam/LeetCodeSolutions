class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hm;
        unordered_map<string, char> hm1;
        int pos = 0, countWords = 0;
        for (char c : pattern) {
            string str;
            while (pos < s.length() && s[pos] == ' ') {
                pos++;
            }
            while (pos < s.length() && s[pos] != ' ') {
                str.push_back(s[pos]);
                pos++;
            }
            if (str.empty() || (hm.contains(c) && hm[c] != str))
                return false;
            if (hm1.contains(str) && hm1[str] != c)
                return false;
            countWords++;
            hm[c] = str;
            hm1[str] = c;
        }
        if (pos < s.length())
            return false;
        return countWords == pattern.length();
    }
};