class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> output(n); 
        vector<int> sorted = score;
        sort(sorted.begin(), sorted.end(), std::greater<>());

        unordered_map<int, string> rankMap;

        for (int i = 0; i < n; i++) {
            if (i == 0) rankMap[sorted[i]] = "Gold Medal";
            else if (i == 1) rankMap[sorted[i]] = "Silver Medal";
            else if (i == 2) rankMap[sorted[i]] = "Bronze Medal";
            else rankMap[sorted[i]] = to_string(i + 1); // Convert integer rank to string
        }

        // Populate the output vector with the ranks according to the original indices
        for (int i = 0; i < n; i++) {
            output[i] = rankMap[score[i]];
        }

        return output;
    }
};