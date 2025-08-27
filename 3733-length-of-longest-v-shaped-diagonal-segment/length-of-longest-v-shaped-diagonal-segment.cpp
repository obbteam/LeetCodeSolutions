class Solution {
public:
    int lenOfVDiagonal(std::vector<std::vector<int>>& grid) {
        const int m = (int)grid.size();
        if (m == 0)
            return 0;
        const int n = (int)grid[0].size();

        // directions: 0:(1,1) 1:(1,-1) 2:(-1,-1) 3:(-1,1)
        static const int dx[4] = {1, 1, -1, -1};
        static const int dy[4] = {1, -1, -1, 1};

        // Flattened DP: index = ((((x*n) + y)*4) + d)*2 + can_turn
        auto idx = [n](int x, int y, int d, int can_turn) -> int {
            return (((x * n + y) << 3) | (d << 1) | can_turn); // *8 == <<3
        };

        std::vector<int> dp(m * n * 8, -1); // 4*2 = 8 states per cell

        // DFS returns max additional steps AFTER taking one step from (x,y)
        // in dir d
        std::function<int(int, int, int, int)> dfs = [&](int x, int y, int d,
                                                         int can_turn) -> int {
            // target depends on current cell
            const int target = (grid[x][y] == 2) ? 0 : 2;

            const int nx = x + dx[d];
            const int ny = y + dy[d];

            // must be able to take at least one straight step
            if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                grid[nx][ny] != target)
                return 0;

            const int key = idx(nx, ny, d, can_turn);
            int& memo = dp[key];
            if (memo != -1)
                return memo;

            // keep going straight
            int best = dfs(nx, ny, d, can_turn);

            // optional single clockwise 90° turn after the step
            if (can_turn) {
                const int nd = (d + 1) % 4; // use (d+3)%4 if problem wants CCW
                best = std::max(best, dfs(nx, ny, nd, 0));
            }

            memo = best + 1; // count the step we just took (nx,ny)
            return memo;
        };

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1)
                    continue;
                // start from each 1, try all 4 directions; +1 counts the
                // starting 1
                for (int d = 0; d < 4; ++d)
                    ans = std::max(ans, dfs(i, j, d, 1) + 1);
            }
        }
        return ans;
    }
};