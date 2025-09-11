class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector height(cols, 0);

        int maxRectangle = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            }

            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                while (!st.empty() &&
                       (j == cols || height[j] < height[st.top()])) {
                    int h = height[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - (st.top() + 1);
                    maxRectangle = max(maxRectangle, h * w);
                }
                st.push(j);
            }
        }

        return maxRectangle;
    }
};