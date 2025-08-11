class Solution {
public:
   std::vector<int> productQueries(int n,
                                std::vector<std::vector<int> > queries) {
    int power = 1, MOD = (int) (1e9 + 7);
    while (power <= n) power <<= 1;
    power >>= 1;

    std::vector<int> powers;
    while (n > 0) {
        if (power <= n) {
            powers.push_back(power);
            n -= power;
        }
        power >>= 1;
    }

    n = powers.size();
    std::vector<std::vector<int> > prefix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        prefix[i][i] = powers[n - 1 - i];
        for (int j = i + 1; j < n; j++)
            prefix[i][j] = static_cast<int>((1L * prefix[i][j - 1] * powers[n - 1 - j]) % MOD);
    }

    std::vector<int> result(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        result[i] = prefix[queries[i][0]][queries[i][1]];
    }
    return result;
}


};