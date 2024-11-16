class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int last = n - 1;

        for(int i = 0; i<n/2; i++) {
            std::swap(matrix[i],matrix[last]);
            last--;
        }

        for(int i = 0; i < n; i++) {
            for(int k = i + 1; k < n; k++) {
                std::swap(matrix[i][k], matrix[k][i]);
            }
        }
    }
};