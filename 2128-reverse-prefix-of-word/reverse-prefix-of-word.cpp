class Solution {
public:
    string reversePrefix(string word, char ch) {
        string sub = "";
        for (int i = 0; i <= word.length(); i++) {
            if (word[i] == ch){
                sub = word.substr(0,i+1);
                word = word.substr(i+1);
                break;
            }
        }
        reverse(sub.begin(), sub.end());
        return sub + word;
    }
};