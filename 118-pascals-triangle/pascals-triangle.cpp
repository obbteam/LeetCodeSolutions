class Solution {
public:
    vector<vector<int>> generate(int n) {
        std::vector<std::vector<int>> res = {};

        res.push_back({1});
        if (n == 1)
            return res;
        res.push_back({1, 1});
        if (n == 2)
            return res;

        for (int i = 2; i < n; ++i) {
            std::vector<int> tmp = {1};
            for (int j = 1; j < i; ++j) {
                tmp.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }
            tmp.push_back(1);
            res.push_back(tmp);
        }
        return res;
    }
};