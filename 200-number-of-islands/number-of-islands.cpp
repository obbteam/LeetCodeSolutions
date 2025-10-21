class Solution {
public:
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs(int i, int j, vector<vector<char>>& grid, unordered_set<string>& visited) {
        queue<vector<int>> q;
        visited.insert(to_string(i) + ',' + to_string(j));

        q.push({i, j});
        while (!q.empty()) {
            auto v = q.front(); q.pop();
            int x = v[0], y = v[1];
            
            for (auto [dx,dy] : directions) {
                auto nx = x + dx;
                auto ny = y + dy;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == '1' && !visited.contains(to_string(nx) + ',' + to_string(ny))) {
                    q.push({nx,ny});
                    visited.insert(to_string(nx) + ',' + to_string(ny));
                }
            }            
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        unordered_set<string> visited;
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1' && !visited.contains(to_string(i) + ',' + to_string(j))) {
                    bfs(i, j, grid, visited);
                    num++;
                }
            }
        }

        return num;
    }
};