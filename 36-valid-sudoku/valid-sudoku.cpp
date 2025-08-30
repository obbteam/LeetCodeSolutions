class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
    unordered_set<char> row[9], cols[9], boxes[9];

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '.')
                continue;
            const auto &c = board[i][j];
            auto boxIdx = (i / 3) * 3 + (j / 3);
            if (row[i].contains(c) || cols[j].contains(c) || boxes[boxIdx].contains(c))
                return false;
            row[i].insert(c);
            cols[j].insert(c);
            boxes[boxIdx].insert(c);
        }
    }

    return true;
}
};