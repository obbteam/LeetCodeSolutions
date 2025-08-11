class Solution {
public:
    
std::vector<int> productQueries(int n, std::vector<std::vector<int> > queries) {
    std::vector<int> powers, result;
    auto x = std::bitset<64>(n);
    for (int i = 0; i < 64; i++) {
        if (x[i] == 1)
            powers.push_back(std::pow(2, i));
    }
    int modulo = std::pow(10, 9) + 7;

    for (auto q: queries) {
        auto start = q[0];
        auto end = q[1];
        long long mul = 1;
        for (int i = start; i <= end; i++) {
                        mul = (mul * powers[i]) % modulo;
        }
        result.push_back(mul);
    }


    return result;
}
};