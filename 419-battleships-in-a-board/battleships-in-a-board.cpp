class Solution {
public:
    int countBattleships(std::vector<std::vector<char>>& board) {
        int battleships = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != 'X')
                    continue;
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;
                if (j > 0 && board[i][j - 1] == 'X')
                    continue;
                battleships++;
            }
        }

        return battleships;
    }
};