#include <unordered_map>

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // init vars
        vector<int> twoIndices;
        std::unordered_map<int, int> HashTable;
        int capacity = nums.size();

        // allocate nums into hash table
        for (int i = 0; i < capacity; i++) {
            HashTable.insert({nums[i], i});
        }
        //looping through all numbers untill sum != target
        for (int i = 0; i < capacity; i++) {
            int second = target - nums[i];
            auto it = HashTable.find(second);
            // ensure that second number exists in our HT and is not the same as nums[i]
            if (it != HashTable.end() && it->second != i) {
                twoIndices.push_back(i);
                twoIndices.push_back(it->second);
                break;
            }
        }
        return twoIndices;
    }
};