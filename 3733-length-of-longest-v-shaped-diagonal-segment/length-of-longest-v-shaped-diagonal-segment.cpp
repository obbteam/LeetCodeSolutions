class Solution {
public:
    vector<pair<int, int>> directions = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    int helper(int x, int y, int d, bool hasMadeTurn, int length,
               vector<vector<int>>& grid) {
        int target = grid[x][y] == 2 ? 0 : 2;

        int nx = x + directions[d].first;
        int ny = y + directions[d].second;
        if (!(nx >= 0 && nx < grid.size() && ny >= 0 &&
              ny < grid[0].size() && grid[nx][ny] == target))
            return length;

        int best = helper(nx, ny, d, hasMadeTurn, length + 1, grid);

        if (!hasMadeTurn) {
            int nd = (d + 1) % 4;
            int target2 = (grid[nx][ny] == 2) ? 0 : 2;
            int rotatedX = nx + directions[nd].first;
            int rotatedY = ny + directions[nd].second;
            if (rotatedX >= 0 && rotatedX < grid.size() && rotatedY >= 0 &&
                rotatedY < grid[0].size() && grid[rotatedX][rotatedY] == target2)
                best = max(best, helper(rotatedX, rotatedY, nd, true,
                                            length + 2, grid));
        }
        return best;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    for (int d = 0; d < 4; ++d)
                        ans = max(ans, helper(i, j, d, false, 1, grid));
            }
        }
        return ans;
    }
};