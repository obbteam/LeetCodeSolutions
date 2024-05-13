class Solution {
public:
    void flipMatrix(bool row, int k, vector<vector<int>>& grid) {
        if (row) {
            for (int& m : grid[k]) {
                m = 1 - m;
            }
        } else if (row == false) {
            for (auto& m : grid) {
                m[k] = 1 - m[k];
            }
        }
    }

    int matrixScore(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][0] == 0)
                flipMatrix(true, i, grid);
        }

        for (int j = 0; j < grid[0].size(); j++) {
            int zeros = 0;
            int ones = 0;
            for (int k = 0; k < grid.size(); k++) {
                if (grid[k][j] == 0)
                    zeros++;
                else
                    ones++;
            }
            if (zeros > ones)
                flipMatrix(false, j, grid);
        }
        // Calculate the final score considering bit positions
        int score = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Left shift bit by place value of column to find column
                // contribution
                int columnScore = grid[i][j] << (grid[0].size() - j - 1);
                // Add contribution to score
                score += columnScore;
            }
        }

        // return final result
        return score;
    }
};