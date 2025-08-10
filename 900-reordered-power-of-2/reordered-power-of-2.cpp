class Solution {
public:
    bool compareDigits(std::unordered_map<int, int> map, int num) {
    while (num > 0) {
        if (!map.contains(num % 10))
            return false;
        map[num % 10]--;
        if (map[num % 10] < 0)
            return false;
        num /= 10;
    }

    for (auto &[num, freq]: map) {
        if (freq != 0)
            return false;
    }
    return true;
}

bool reorderedPowerOf2(int n) {
    std::unordered_map<int, int> digitFreqs;

    while (n > 0) {
        digitFreqs[n % 10]++;
        n /= 10;
    }

    for (int i = 0; i <= 30; i++) {
        int power2 = (int) std::pow(2, i);

        if (compareDigits(digitFreqs, power2))
            return true;
    }
    return false;
}
};