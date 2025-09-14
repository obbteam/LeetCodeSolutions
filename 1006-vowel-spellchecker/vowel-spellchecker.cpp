class Solution {
public:
    string makeLower(string word) {
        for (char& c : word)
            c = tolower(c);
        return word;
    };

    string deVowel(string word) {
        for (char& c : word)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        return word;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> wordSet(wordlist.begin(), wordlist.end());
        unordered_map<string, string> lowered;
        unordered_map<string, string> deVoweled;

        for (string word : wordlist) {
            auto lower = makeLower(word);
            auto noVowel = deVowel(lower);

            if (!lowered.contains(lower))
                lowered[lower] = word;
            if (!deVoweled.contains(noVowel))
                deVoweled[noVowel] = word;
        }

        vector<string> result;
        for (string q : queries) {
            if (wordSet.contains(q))
                result.push_back(q);
            else {
                auto lower = makeLower(q);
                auto noVowel = deVowel(lower);

                if (lowered.contains(lower))
                    result.emplace_back(lowered[lower]);
                else if (deVoweled.contains(noVowel))
                    result.emplace_back(deVoweled[noVowel]);
                else
                    result.emplace_back("");
            }
        }
        return result;
    }
};