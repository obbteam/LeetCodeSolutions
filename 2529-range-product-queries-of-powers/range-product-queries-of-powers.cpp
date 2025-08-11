class Solution {
public:
    std::vector<int> productQueries(int n,
                                    std::vector<std::vector<int>> queries) {
        std::vector<int> exponents, result;
        int i = 0, j = 0;
        while (n) {
            if (n & 1) {
                exponents.push_back(i);
                if (j)
                    exponents[j] += exponents[j - 1];
                j++;
            }
            n = n >> 1;
            i++;
        }
        int modulo = std::pow(10,9) + 7;
        for (auto q : queries) {
            int p = exponents[q[1]] - (q[0] ? exponents[q[0] - 1] : 0);
            int res = 1;
            for (int i = 0; i < p; i++) {
                res = (res * 2) % modulo;
            }
            result.push_back(res);
        }

        return result;
    }
};