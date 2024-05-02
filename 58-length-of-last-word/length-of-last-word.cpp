class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length() - 1;
        int count = 0;
        while (isspace(s[size])) {
            size--;
        }
        while (size >= 0 && isalpha(s[size])) {
            count++;
            size--;
        }
        return count;
    }
};