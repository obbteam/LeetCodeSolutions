class Solution {
public:
    int partitionString(string s) {
        vector<char> arr(26, 0);
        vector<char> cleaned(26, 0);
        int count = 1;
        for (auto& c : s) {
            if (arr[c - 'a'] == 1) {
                count++;
                arr = cleaned;
            }
            arr[c - 'a']++;
        }

        return count;
    }
};