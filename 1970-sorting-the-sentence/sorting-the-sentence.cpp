class Solution {
public:
    string sortSentence(string s) {
        map<int, string> myArray;
        string result;
        int i = 0, prevPos = 0;
        while (s[i] != '\0') {
            if (isdigit(s[i])) {
                myArray[int(s[i])] = s.substr(prevPos, i - prevPos);
                prevPos = i + 2;
            }
            i++;
        }

        for (auto k : myArray) {
            result += k.second + " ";
        }

        if (!result.empty())
            result.pop_back();
        return result;
    }
};