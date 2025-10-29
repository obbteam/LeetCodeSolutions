class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> prefixMax(n, 0), sufixMax(n, 0);

        int prevMax = height[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = prevMax;
            prevMax = max(prevMax, height[i]);
        }

        prevMax = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            sufixMax[i] = prevMax;
            prevMax = max(prevMax, height[i]);
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int water_level = min(prefixMax[i], sufixMax[i]);
            sum += max(0, water_level - height[i]);
        }

        return sum;
    }
};