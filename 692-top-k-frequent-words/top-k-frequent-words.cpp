class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        freq.reserve(words.size());
        for(auto &w : words) {
            freq[w]++;
        }

        priority_queue<pair<int, string>> pq;
        for (auto &it : freq) {
            pq.push({-it.second, it.first});
            if (pq.size() > k) pq.pop();
        }


        vector<string> ans(k);
        for (int i = 0; i < k; ++i) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};