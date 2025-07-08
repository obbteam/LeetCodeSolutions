class Solution {
public:
    string removeStars(string s) {
        std::stack<char> word;
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*')
                word.push(s[i]);
            else
                word.pop();
        }

        while (!word.empty()) {
            res+=word.top();
            word.pop();
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};