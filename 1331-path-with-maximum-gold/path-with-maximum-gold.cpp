class Solution {
public:
    vector<int> rows = {1, 0, -1, 0};
    vector<int> cols = {0, 1, 0, -1};
    int maxGold = 0;

    int checkPaths(int x, int y, int m, int n, vector<vector<int>>& grid) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            return 0;

        int curr = grid[x][y];
        grid[x][y] = 0;

        int tempMax = curr;
        for (int i = 0; i < 4; i++) {
            int newX = x + rows[i];
            int newY = y + cols[i];
            tempMax = max(tempMax, curr + checkPaths(newX, newY, m, n, grid));
        }
        grid[x][y] = curr;
        return tempMax;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, checkPaths(i, j, m, n, grid));
                }
            }
        }
        return maxGold;
    }
};