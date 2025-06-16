class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stack<std::string> stack;
        s = s.substr(s.find_first_not_of(' '),
                     s.find_last_not_of(' ') - s.find_first_not_of(' ') + 1);

        std::string word;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ')
                word += s[i];
            else {
                if (!word.empty())
                    stack.push(word);
                word = "";
            }
        }
        stack.push(word);

        string res;
        while (!stack.empty()) {
            res += stack.top();
            stack.pop();
            if (!stack.empty())
                res += " ";
        }

        return res;
    }
};