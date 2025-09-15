class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char c : brokenLetters)
            broken.insert(c);

        int num = 0;
        bool skip = false;
        for (int i = 0; i < text.length(); ++i) {
            if (!skip && broken.contains(text[i]))
                skip = true;

            if (text[i] == ' ' || i == text.length() - 1) {
                if (!skip)
                    num++;
                skip = false;
            }
        }

        return num;
    }
};