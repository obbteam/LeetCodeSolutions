class Solution {
public:
    std::string sortVowels(std::string s) {
        std::vector<char> vowels;

        for (char c : s)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                vowels.push_back(c);

        if (vowels.empty())
            return s;

        std::sort(vowels.begin(), vowels.end());

        int j = 0;
        for (char& i : s) {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' ||
                i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
                i = vowels[j++];
        }
        return s;
    }
};