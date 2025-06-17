class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin();
        auto right = height.end() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = min(*left, *right) * (right - left);
            maxArea = max(maxArea, area);
            if (*left >= *right)
                --right;
            else
                ++left;
        }
        return maxArea;
    }
};