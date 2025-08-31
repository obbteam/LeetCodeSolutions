class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!std::isalnum(s[i]))
                i++;
            if (!std::isalnum(s[j]))
                j--;

            if (std::isalnum(s[i]) && std::isalnum(s[j])) {
                if (std::tolower(s[i]) != std::tolower(s[j]))
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};