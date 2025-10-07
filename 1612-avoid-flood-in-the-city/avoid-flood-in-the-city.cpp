class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector ans(rains.size(), 1);

        unordered_map<int, int> lastRain;
        set<int> dryIdx;
        
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0){
                dryIdx.insert(i);
            } else {
                ans[i] = -1;
                if (lastRain.count(rains[i])){
                    auto it = dryIdx.upper_bound(lastRain[rains[i]]);
                    if (it == dryIdx.end()) return {};
                    ans[*it] = rains[i];
                    dryIdx.erase(it);
                }

                lastRain[rains[i]] = i;
            }
        }

        return ans;
    }
};