class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& i : nums) {
            freq[i]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for(const auto &[num, count] : freq) {
            bucket[count].emplace_back(num);
        }

        for (int i = bucket.size() - 1; i > 0; --i) {
            if (!bucket[i].empty()) {
                return i * bucket[i].size();
            }
        }
        return 0;
    }
};