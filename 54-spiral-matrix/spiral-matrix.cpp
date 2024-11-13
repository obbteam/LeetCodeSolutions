class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    int step = 0;
    int l = 0;
    int m_size = (m + 1) * (n + 1);
    std::vector<int> result;
    int i = 0;
    int k = 0;

    while (l < m_size) {
        for (int j = k; j <= n - step; ++j) {
            l++;
            result.push_back(matrix[i][j]);
            k = j;
        }
        if(l >= m_size) break;

        i++;
        for (int j = i; j <= m - step; j++) {
            l++;
            result.push_back(matrix[j][k]);
            i = j;
        }
        if(l >= m_size) break;

        k--;

        for (int j = k; j >= step; j--) {
            l++;
            result.push_back(matrix[i][j]);
            k = j;
        }

        if(l >= m_size) break;
        i--;

        for (int j = i; j >= step + 1; j--) {
            l++;
            result.push_back(matrix[j][k]);
            i = j;
        }

        if(l >= m_size) break;
        k++;
        step++;
    }


    return result;
    }
};