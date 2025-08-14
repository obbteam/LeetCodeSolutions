class Solution {
public:
    std::string largestGoodInteger(std::string num) {
    if (num.length() < 3)
        return "";

    int uniqueDigit = -1;

    for (int i = 2; i < num.length(); i++) {
        if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
            uniqueDigit = std::max(uniqueDigit, num[i] - '0');
        }
        if (uniqueDigit == 9)
            break;
    }

    if (uniqueDigit == -1)
        return "";

    return std::string(3, '0' + uniqueDigit);
}

};