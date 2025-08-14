class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::tuple<int, int, int>> q;
        int minutes = 0, freshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 2)
                    q.emplace(i, j, minutes);
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        while (!q.empty() && freshOranges != 0) {
            auto [x, y, localMinutes] = q.front();
            q.pop();

            if (grid[x][y] == 1) {
                grid[x][y] = 2;
                freshOranges--;
            }

            if (x - 1 >= 0 && grid[x - 1][y] == 1)
                q.emplace(x - 1, y, localMinutes + 1);

            if (x + 1 < grid.size() && grid[x + 1][y] == 1)
                q.emplace(x + 1, y, localMinutes + 1);

            if (y - 1 >= 0 && grid[x][y - 1] == 1)
                q.emplace(x, y - 1, localMinutes + 1);

            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
                q.emplace(x, y + 1, localMinutes + 1);

            minutes = std::max(minutes, localMinutes);
        }

        return freshOranges == 0 ? minutes : -1;
    }
};