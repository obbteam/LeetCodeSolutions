class Solution {
public:
    using ll = long long;
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        std::string fraction;
        if ((numerator < 0) ^ (denominator < 0)) fraction+="-";
        
        ll num = std::llabs((long long)numerator);        
        ll denom = std::llabs((long long)denominator);
        
        fraction+= std::to_string(num / denom);

        ll remainder = num % denom;
        if (remainder == 0) return fraction;

        fraction+=".";

        unordered_map<ll, int> hm;
        while (remainder != 0) {
            if (hm.count(remainder)) {
                fraction.insert(hm[remainder], "(");
                fraction+=")";
                break;
            }

            hm[remainder] = fraction.size();
            remainder*=10;
            fraction+=std::to_string(remainder / denom);
            remainder %= denom;
        }

        return fraction;

    }
};