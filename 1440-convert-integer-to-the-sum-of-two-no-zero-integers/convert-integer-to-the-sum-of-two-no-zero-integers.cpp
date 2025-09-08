class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto nonZero = [](int a) {
            for (; a > 0; a /= 10) {
                if (a % 10 == 0)
                    return false;
            }
            return true;
        };

        for (int i = 1; i <= n / 2; ++i) {
            if (nonZero(i) && nonZero(n - i))
                return {i, n - i};
        }
        return {};
    }
};