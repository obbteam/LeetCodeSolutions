class Solution {
public:
    std::string phone[10] = {{},      {},      {"abc"},  {"def"}, {"ghi"},
                             {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

    void backTrack(int i, std::vector<string>& result, std::string path,
                   string& digits) {
        if (i == digits.length()) {
            result.push_back(path);
            return;
        }

        string letters = phone[digits[i] - '0'];
        for (auto c : letters) {
            backTrack(i + 1, result, path + c, digits);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> result;
        backTrack(0, result, "", digits);
        return result;
    }
};