class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        freq.reserve(words.size());
        for(auto &w : words) {
            freq[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for (auto &[w, f] : freq) {
            pq.push({f, w});
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