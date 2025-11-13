class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
            
        for (auto s : strs) {
            array<int, 26> letters = {0};

            for (auto l : s) {
                letters[l - 'a']++;
            }

            string key;
            for (auto l : letters) {
                key += to_string(l) + 'a';
            }
            map[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto [key, words] : map) {
            ans.push_back(words);
        }
        return ans;
    }
};