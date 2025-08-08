class Solution {
public:
    std::vector<int> goodDaysToRobBank(std::vector<int>& security, int time) {
        if (time > security.size())
            return {};

        std::vector decreasing(security.size(), std::make_pair(0, 0));
        // fill the decreasing
        for (int i = 1; i < security.size(); i++) {
            if (security[i] <= security[i - 1])
                decreasing[i].first = decreasing[i - 1].first + 1;
            else
                decreasing[i].first = 0;
        }

        // fill the decreasing backwards
        for (int i = security.size() - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1])
                decreasing[i].second = decreasing[i + 1].second + 1;
            else
                decreasing[i].second = 0;
        }

        std::vector<int> result;
        for (int i = 0; i < decreasing.size(); i++) {
            if (decreasing[i].first >= time && decreasing[i].second >= time)
                result.push_back(i);
        }

        return result;
    }
};