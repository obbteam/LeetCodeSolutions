class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0)
            return {};
        int n = mat[0].size();
        vector<int> res;
        int i = 0, j = 0;
        while (res.size() < m * n) {
            // up right
            while (i >= 0 && j < n) {
                res.push_back(mat[i][j]);
                i--;
                j++;
            }
            if (j >= n) {
                j = n - 1;
                i += 2;
            } else if (i < 0)
                i = 0;

            // down left
            while (j >= 0 && i < m) {
                res.push_back(mat[i][j]);
                i++;
                j--;
            }
            if (i >= m) {
                i = m - 1;
                j += 2;
            } else if (j < 0)
                j = 0;
        }
        return res;
    }
};