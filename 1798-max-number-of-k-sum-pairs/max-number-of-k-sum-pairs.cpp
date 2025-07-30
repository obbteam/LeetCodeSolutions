class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freqs;
        int count = 0;
        freqs.reserve(nums.size());

        for (auto& x : nums) {
            if (freqs[k - x] > 0) {
                count++;
                freqs[k - x]--;
            } else {
                freqs[x]++;
            }
        }
        return count;
    }
};