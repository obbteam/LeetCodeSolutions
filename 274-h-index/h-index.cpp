class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());

        int n = citations.size(), h = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (citations[i] >= n - i) h = max(h, n - i);
        }

        return h;
    }
};