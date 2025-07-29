class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int zeros = 0, ones = 0;
        vector<int> result;
        for (auto& num : nums) {
            if (num % 2 == 0)
                zeros++;
            else
                ones++;
        }

        for (int i = 0; i < zeros; ++i)
            result.emplace_back(0);
        for (int i = 0; i < ones; ++i)
            result.emplace_back(1);

        return result;
    }
};