class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (auto w : words) {
            if (ans.empty()) {
                ans.push_back(w);
                continue;
            }
            string a = w;
            string x = ans.back();
            sort(a.begin(), a.end());
            sort(x.begin(), x.end());

            if (a != x) ans.push_back(w);
        }

        return ans;
    }
};