class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> matrix(m,
                                             std::vector(n, 1)); // m x n matrix

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
            }
        }
        return matrix[0][0];
    }
};