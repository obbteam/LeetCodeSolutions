class Solution {
public:
    int gcd(int u, int v) {
        auto shift = __builtin_ctz(u | v);
        u >>= __builtin_ctz(u);
        do {
            v >>= __builtin_ctz(v);
            if (u > v)
                std::swap(u, v);
        } while ((v -= u));
        return u << shift;
    }

    long long lcm(int a, int b) {
        // larger value
        int g = max(a, b);

        // Smaller value
        int s = min(a, b);

        for (long long i = g; i <= (long long)a * b; i += g) {
            if (i % s == 0)
                return i;
        }
        return INT_MIN;
    }

    bool areNonCoprime(int a, int b) {
        if (!((a | b) & 1))
            return true; // Both are even numbers, divisible by at least 2.
        return 1 != gcd(a, b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;

        for (auto num : nums) {
            res.emplace_back(num);
            while (res.size() > 1 &&
                   areNonCoprime(res.back(), *(res.end() - 2))) {
                auto lcmNum = lcm(res.back(), *(res.end() - 2));
                res.pop_back();
                res.pop_back();
                res.emplace_back(lcmNum);
            }
        }
        return res;
    }
};