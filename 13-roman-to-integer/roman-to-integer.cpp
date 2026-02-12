static std::unordered_map<char, int> romanChars = {
        {'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;

        for (int i = 0; i < s.length() - 1; ++i) {
            auto cur = romanChars[s[i]];
            auto next = romanChars[s[i+1]];

            if (cur < next) res -= cur;
            else res += cur;
        }

        res+=romanChars[s[s.length() - 1]];

        return res;
    }    
};