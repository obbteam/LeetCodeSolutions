class Solution {
public:
    bool isIsomorphic(string s, string t) {
    std::unordered_map<char, char> map;
    std::unordered_map<char, char> map1;

    for (int i = 0; i < s.length(); i++) {
        if (map.contains(s[i]) && map[s[i]] != t[i])
            return false;
        if (map1.contains(t[i]) && map1[t[i]] != s[i])
            return false;
        map[s[i]] = t[i];
        map1[t[i]] = s[i];
    }
    return true;
}
};