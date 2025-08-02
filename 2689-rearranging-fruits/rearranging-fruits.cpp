class Solution {
public:
    long long minCost(std::vector<int> &basket1, std::vector<int> &basket2) {
    std::unordered_map<int, int> freqs1, freqs2;
    int minNumber = INT_MAX;

    for (auto &num: basket1) {
        freqs1[num]++;
        minNumber = std::min(minNumber, num);
    }
    for (auto &num: basket2) {
        freqs2[num]++;
        minNumber = std::min(minNumber, num);
    }

    std::vector<std::pair<int, int> > toSwap;

    for (auto &[num, freq]: freqs1) {
        if (!freqs2.contains(num)) {
            if (freq % 2 != 0)
                return -1;
            toSwap.emplace_back(std::make_pair(num, freq / 2));
        } else if ((freqs2[num] + freq) % 2 != 0)
            return -1;
        else if (freqs2[num] != freq)
            toSwap.emplace_back(std::make_pair(num, std::abs(freq - freqs2[num]) / 2));
    }

    for (auto &[num, freq]: freqs2) {
        if (!freqs1.contains(num)) {
            if (freq % 2 != 0)
                return -1;
            toSwap.emplace_back(std::make_pair(num, freq / 2));
        }
    }

    std::sort(toSwap.begin(), toSwap.end());


    long long ans = 0;
    int start = 0, end = toSwap.size() - 1;
    while (start <= end) {
        toSwap[end].second--;
        toSwap[start].second--;
        int medium = std::min(toSwap[start].first, toSwap[end].first);
        ans+=std::min(medium, 2*minNumber);
        if (toSwap[start].second == 0) {
            start++;
        }
        if (toSwap[end].second == 0) {
            end--;
        }
    }


    return ans;
}
};