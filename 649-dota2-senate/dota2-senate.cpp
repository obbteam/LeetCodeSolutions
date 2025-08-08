class Solution {
public:
    std::string predictPartyVictory(std::string senate) {
        std::queue<char> banList;

        std::string won;
        while (won.empty()) {
            for (auto& c : senate) {
                if (c == '_')
                    continue;
                if (banList.front() == c) {
                    c = '_';
                    banList.pop();
                } else
                    banList.push(c == 'R' ? 'D' : 'R');
            }

            char prev = '_';
            for (auto& c : senate) {
                if (c == '_')
                    continue;

                if (prev != '_' && c != prev) {
                    won = "";
                    break;
                }
                prev = c;
                won = prev == 'R' ? "Radiant" : "Dire";
            }
        }

        return won;
    }
};