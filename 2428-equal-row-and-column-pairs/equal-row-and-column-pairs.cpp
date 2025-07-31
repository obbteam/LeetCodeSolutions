class Solution {
public:
    int equalPairs(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), count = 0;

        if (n == 0 || n != grid[0].size()) {
            return 0;
        }

        for (int i = 0; i < n; i++) {
            auto& row = grid[i];

            for (int j = 0; j < n; j++) {
                bool equals = true;

                for (int k = 0; k < n; k++) {
                    if (row[k] != grid[k][j]) {
                        equals = false;
                        break;
                    }
                }

                if (equals)
                    count++;
            }
        }
        return count;
    }
};