class Solution {
public:
    int pushChar(int pos, char c, int streak, std::vector<char> &chars) {
    chars[pos] = c;
    pos++;

    if (streak > 1) {
        std::string num = std::to_string(streak);
        for (int i = 0; i < num.length(); i++) {
            chars[pos + i] = num[i];
        }
        pos += num.length();
    }
    return pos;
}

int compress(std::vector<char> &chars) {
    if (chars.size() <= 1)
        return 1;

    int streak = 1, pos = 0;
    char prev = chars[0];

    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == prev)
            streak++;
        else if (chars[i] != prev && streak <= 1) {
            pos = pushChar(pos, prev, streak, chars);
            prev = chars[i];
        } else {
            pos = pushChar(pos, prev, streak, chars);
            streak = 1;
            prev = chars[i];
        }
    }

    pos = pushChar(pos, prev, streak, chars);

    for (auto &c: chars) {
        std::cout << c << std::endl;
    }
    return pos;
}
};