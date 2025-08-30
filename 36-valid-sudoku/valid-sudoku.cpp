class Solution {
public:
    vector<int> validRowColBox = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    bool isValidSudoku(vector<vector<char>>& board) {
        for (const auto& row : board) {
            auto valid = validRowColBox;
            for (const auto el : row) {
                if (el != '.') {
                    valid[el - '0']--;
                    if (valid[el - '0'] < 0)
                        return false;
                }
            }
        }
        for (int i = 0; i < board[0].size(); i++) {
            auto valid = validRowColBox;
            for (auto& el : board) {
                if (el[i] != '.') {
                    valid[el[i] - '0']--;
                    if (valid[el[i] - '0'] < 0)
                        return false;
                }
            }
        }

        // 9 squares to check
        for (int xOffset = 0; xOffset < 9; xOffset += 3) {
            for (int yOffset = 0; yOffset < 9; yOffset += 3) {
                auto valid = validRowColBox;

                for (int i = 0 + xOffset; i < 3 + xOffset; i++) {
                    for (int j = 0 + yOffset; j < 3 + yOffset; j++) {
                        if (board[i][j] != '.') {
                            valid[board[i][j] - '0']--;
                            if (valid[board[i][j] - '0'] < 0)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};