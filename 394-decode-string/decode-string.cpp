class Solution {
public:
    std::string decodeString(std::string s) {
        std::string curr;
        std::stack<std::string> substrStack;
        std::stack<int> countStack;
        int num = 0;

        for (auto& c : s) {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '[') {
                countStack.push(num);
                substrStack.push(curr);
                curr = "";
                num = 0;
            } else if (c == ']') {
                int k = countStack.top();
                countStack.pop();
                std::string temp;
                temp.reserve(curr.size() * k);
                while (k--)
                    temp += curr;
                curr = substrStack.top() + temp;
                substrStack.pop();

            } else {
                curr += c;
            }
        }

        return curr;
    }
};