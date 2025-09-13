class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> letterCount;
        for (char c : s)
            letterCount[c]++;

        int maxVowel = 0, maxConsonant = 0;
        for (auto [letter, count] : letterCount) {
            if (letter == 'a' || letter == 'e' || letter == 'i' ||
                letter == 'o' || letter == 'u') {
                if (count > maxVowel)
                    maxVowel = count;
            } else if (count > maxConsonant)
                maxConsonant = count;
        }
        return maxVowel + maxConsonant;
    }
};