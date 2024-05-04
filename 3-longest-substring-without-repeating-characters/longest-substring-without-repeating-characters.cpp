class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        string longest = "";
        for (int i = 0; i < s.length(); i++) {
            if (longest.find(s[i]) == string::npos) {
                longest.push_back(s[i]);
            } else {
                if (result < longest.length())
                    result = longest.length();
                longest = "";
                auto pos = s.find_first_of(s[i]);
                s = s.substr(pos + 1);
                i = -1;
            }
        }
        if (result < longest.length())
            result = longest.length();
        return result;
    }
};