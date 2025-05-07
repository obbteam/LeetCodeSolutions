class Solution {
public:
    vector<int> getRow(int n) {
        std::vector<int> res(1,1);

        for (int i = 0; i < n; ++i) {
            std::vector<int> tmp;
            tmp.push_back(1);

            for (int j = 1; j < res.size(); ++j) {
                tmp.push_back(res[j] + res[j - 1]);
            }

            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};