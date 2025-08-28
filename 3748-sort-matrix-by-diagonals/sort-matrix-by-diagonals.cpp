class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int j = n - 1; j > 0; j--) {
            int i = 0, k = j;
            vector<int> diag;

            // down right
            while (i < m && k < n) {
                diag.push_back(grid[i++][k++]);
            }

            std::sort(diag.begin(), diag.end());

            int idx = 0;
            i = 0, k = j;
            while (i < m && k < n) {
                grid[i++][k++] = diag[idx++];
            }
        }

        for (int i = 0; i < m; i++) {
            int k = i;
            int j = 0;
            vector<int> diag;

            // down right
            while (k < m && j < n) {
                diag.push_back(grid[k++][j++]);
            }

            std::sort(diag.begin(), diag.end(), std::greater<int>());

            int idx = 0;
            k = i, j = 0;
            while (k < m && j < n) {
                grid[k++][j++] = diag[idx++];
            }
        }

        return grid;
    }
};