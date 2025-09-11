class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    std::string sortVowels(std::string s) {
        std::unordered_map<char, int> vowels;

        for (char c : s)
            if (isVowel(c))
                vowels[c]++;

        if (vowels.empty())
            return s;

        int j = 0;
        std::string sortedVowels = "AEIOUaeiou";
        std::string result;
        for (char c : s)
            if (!isVowel(c))
                result += c;
            else {
                while (vowels[sortedVowels[j]] == 0)
                    j++;
                result += sortedVowels[j];
                vowels[sortedVowels[j]]--;
            }

        return result;
    }
};