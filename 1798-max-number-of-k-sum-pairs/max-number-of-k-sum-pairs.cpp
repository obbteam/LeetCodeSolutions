class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::ranges::sort(nums);
        int count = 0;
        auto start = nums.begin();
        auto end = nums.end() - 1;

        while (start < end) {
            if (*start + *end == k) {
                count++;
                ++start;
                --end;
            } else if (*start + *end > k)
                --end;
            else
                ++start;
        }

        return count;
    }
};