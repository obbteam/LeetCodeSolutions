class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> count (maxValue - minValue + 1);

        for (auto num : nums) {
            count[num - minValue]++;
        }

        for (int i = count.size() - 1; i >=0; --i) {
            k -= count[i];
            if (k <= 0)
                return i + minValue;
        }

        return -1;
    }
};