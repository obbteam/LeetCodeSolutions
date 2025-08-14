class Solution {
public:
    void dfs(std::vector<std::vector<char>>& board, std::pair<int, int> pos,
             std::pair<int, int> direction) {
        board[pos.first][pos.second] = '.';

        auto nx = pos.first + direction.first,
             ny = pos.second + direction.second;

        if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() ||
            board[nx][ny] != 'X')
            return;

        dfs(board, {nx, ny}, direction);
    }

    int countBattleships(std::vector<std::vector<char>>& board) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int battleships = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'X') {
                    battleships++;
                    for (auto d : directions) {
                        dfs(board, {i, j}, {d[0], d[1]});
                    }
                }
            }
        }

        return battleships;
    }
};