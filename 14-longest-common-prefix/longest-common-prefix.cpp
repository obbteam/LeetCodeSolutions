class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        int k = 1;

        while (k != strs.size()) {
            int lengthToCompare = min(prefix.length(), strs[k].length());
            int i = 0;
            for (; i < lengthToCompare; i++) {
                if (strs[k][i] != prefix[i]) {
                    prefix = prefix.substr(0, i);
                    break;
                }
            }
            // If no mismatch is found but `strs[k]` is shorter than `prefix`
            if (i == lengthToCompare && lengthToCompare < prefix.length()) {
                prefix = prefix.substr(0, lengthToCompare);
            }

            if (prefix.empty())
                return prefix;
            k++;
        }
        return prefix;
    }
};