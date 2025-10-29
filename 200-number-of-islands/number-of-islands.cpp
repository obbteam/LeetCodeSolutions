class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));


        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1' && visited[r][c] == 0) {
                    islands++;
                    bfs(grid, r, c, visited, rows, cols);
                }
            }
        }

        return islands;        
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited, int rows, int cols) {
        queue<pair<int, int>> q;
        visited[r][c] = 1;
        q.push({r, c});

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1' && visited[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }
    }
};    