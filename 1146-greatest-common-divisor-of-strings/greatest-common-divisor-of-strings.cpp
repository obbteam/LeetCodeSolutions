class Solution {
public:
    

string gcdOfStrings(string str1, string str2) {
    string shorter_str = str1;
    if (str1.length() > str2.length()) {
        shorter_str = str2;
    }

    while (!shorter_str.empty()) {
        if (str1.length() % shorter_str.length() == 0 &&
            str2.length() % shorter_str.length() == 0) {
            bool gcd = true;
            for (size_t i = 0; i < str1.length() && gcd; ++i)
                if (str1[i] != shorter_str[i % shorter_str.length()])
                    gcd = false;

            for (size_t i = 0; i < str2.length() && gcd; ++i)
                if (str2[i] != shorter_str[i % shorter_str.length()])
                    gcd = false;

            if (gcd)
                return shorter_str;
        }
        shorter_str.pop_back();
    }
    return "";
}

};