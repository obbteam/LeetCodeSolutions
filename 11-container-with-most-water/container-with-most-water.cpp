class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, maxA = 0;

        while (l < r) {
            int localA = min(height[l], height[r]) * (r - l);
            maxA = max(maxA, localA);
            if (height[l] >= height[r]) r--;
            else l++;
        }

        return maxA;
    }
};