class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < min(strs[i].length(), lcp.length()); ++j) {
                if (strs[i][j] != lcp[j]) {
                    lcp = lcp.substr(0, j);
                    break;
                }
            }
            lcp = lcp.substr(0, min(strs[i].length(), lcp.length()));
            if (lcp.length() == 0) break;
        }
        return lcp;
    }
};