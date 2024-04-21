#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::unordered_map<char, int> HashTable;
        for (char i : magazine) {
            HashTable[i]++;
        }
        for (char i : ransomNote) {
            auto it = HashTable.find(i);
            if (it == HashTable.end() || it->second == 0) {
                return false;
            }
            it->second--;
        }
        
        return true;
    };
};