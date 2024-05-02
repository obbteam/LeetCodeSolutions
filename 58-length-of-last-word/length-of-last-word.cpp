class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length() - 1;
        int count = 0;
        for (; size >= 0; size--) {
            if (s[size] != ' ') {
                count++;
            }
            if (count && s[size] == ' ')
                break;
        }
        return count;
    }
};