class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int totalTriangles = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    totalTriangles += r - l;
                    r--;
                } else
                    l++;
            }
        }

        return totalTriangles;
    }
};