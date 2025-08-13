class Solution {
public:
    bool isExit(int x, int y, int m, int n, int entranceX, int entranceY) {
        if (x == entranceX && y == entranceY)
            return false;

        if (x == 0 || x == m)
            return true;

        if (y == 0 || y == n)
            return true;

        return false;
    }

    int nearestExit(std::vector<std::vector<char>>& maze,
                    std::vector<int>& entrance) {
        std::queue<std::tuple<int, int, int>> q;
        int m = maze.size(), n = maze[0].size();

        int minPath = INT_MAX;
        q.push(std::tuple{entrance[0], entrance[1], 0});
        while (!q.empty()) {
            auto [x, y, k] = q.front();
            q.pop();
            if (maze[x][y] == '#')
                continue;
            if (maze[x][y] == '+')
                continue;

            maze[x][y] = '#';

            if (isExit(x, y, m - 1, n - 1, entrance[0], entrance[1]))
                minPath = std::min(minPath, k);

            // up
            if (x - 1 >= 0 && maze[x - 1][y] == '.')
                q.push(std::make_tuple(x - 1, y, k + 1));

            // right
            if (y + 1 < n && maze[x][y + 1] == '.')
                q.push(std::make_tuple(x, y + 1, k + 1));

            // down
            if (x + 1 < m && maze[x + 1][y] == '.')
                q.push(std::make_tuple(x + 1, y, k + 1));

            // left
            if (y - 1 >= 0 && maze[x][y - 1] == '.')
                q.push(std::make_tuple(x, y - 1, k + 1));
        }

        return minPath == INT_MAX ? -1 : minPath;
    }
};