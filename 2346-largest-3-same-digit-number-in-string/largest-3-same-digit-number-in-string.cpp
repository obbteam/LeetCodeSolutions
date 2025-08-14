class Solution {
public:
    std::string largestGoodInteger(std::string num) {
        if (num.length() < 3)
            return "";

        std::string largestGoodInteger;

        for (int i = 2; i < num.length(); i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
                if (largestGoodInteger.empty() ||
                    std::stoi(num.substr(i - 2, 3)) > std::stoi(largestGoodInteger))
                    largestGoodInteger = num.substr(i - 2, 3);
            }
        }

        return largestGoodInteger;
    }
};