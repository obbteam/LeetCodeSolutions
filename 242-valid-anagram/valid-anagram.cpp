class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> countMap;

        for (auto c : s)
            countMap[c]++;
        
        for (auto c : t){
            countMap[c]--;
            if (countMap[c] < 0)
            return false;
        }
        return true;
    }
};