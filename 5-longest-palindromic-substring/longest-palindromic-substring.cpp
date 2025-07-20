class Solution {
public:
    string expand(int l, int r, std::string &s) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }

    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    string maxP = "";

    if (s.length() < 2) {
        return s;
    }

    for (int i = 0; i < s.length(); i++) {
        string first = expand(i, i, s);
        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            string second = expand(i, i + 1, s);
            first = second.length() > first.length() ? second : first;
        }

        maxP = first.length() > maxP.length() ? first : maxP;
    }

    return maxP;
}
};