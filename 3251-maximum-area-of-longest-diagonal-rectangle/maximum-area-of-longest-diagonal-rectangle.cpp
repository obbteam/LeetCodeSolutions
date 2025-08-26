class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int longestDiagonal = 0;
        int maxArea = 0;
        for (auto d : dimensions) {
            int x = d[0], y = d[1];
            int diag = x * x + y * y;
            if (diag > longestDiagonal) {
                longestDiagonal = diag;
                maxArea = x * y;
            } else if (diag == longestDiagonal)
                maxArea = max(maxArea, x * y);
        }
        return maxArea;
    }
};