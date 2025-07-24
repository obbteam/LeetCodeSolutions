class Solution {
public:
    int isVowel(char c) {
        switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return 1;
        default:
            return 0;
        }
    }

    int maxVowels(std::string s, int k) {
        int result = 0, cur = 0;
        // first window
        for (int i = 0; i < k && i < s.length(); i++)
            cur += isVowel(s[i]);

        result = cur;

        for (int i = k; i < s.length(); ++i) {
            cur += isVowel(s[i]);
            cur -= isVowel(s[i - k]);

            result = std::max(cur, result);

            if (result >= k)
                return result;
        }
        return result;
    }
};