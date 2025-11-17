class Solution {
public:
    int lengthOfLastWord(string s) {
        bool start = false;
        int l = 0;     
        for(int i = s.length() - 1; i >= 0; --i) {
            if (s[i] != ' ' && start == false ) start = true;
            else if (s[i] == ' ' && start) break;

            if (start) l++;
        }
        return l;
    }
};