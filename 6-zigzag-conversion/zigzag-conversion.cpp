class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> conv(numRows, "");
        int i = 0, direction = 1;
        for(auto &c : s) {
            if (i == 0) direction = 1;
            else if (i == numRows - 1) direction = -1;
            conv[i] += c;
            i += direction;
        }

        string converted;
        converted.reserve(s.length());
        for(auto &s : conv) {
            converted += s;
        }
        return converted;
    }
};