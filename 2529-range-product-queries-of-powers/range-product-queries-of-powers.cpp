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
        for (auto q : queries) {
            int p = exponents[q[1]] - (q[0] ? exponents[q[0] - 1] : 0);
            int res = 1;
            result.push_back(modPow(2,p));
        }

        return result;
    }

    long long modPow(long long base, long long exp) {
        int MOD = 1000000007;
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1) ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

};