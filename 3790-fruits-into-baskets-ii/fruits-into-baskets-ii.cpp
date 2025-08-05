class Solution {
public:
    int numOfUnplacedFruits(std::vector<int> &fruits, std::vector<int> &baskets) {
    int count = 0;

    for (int i = 0; i < fruits.size(); i++) {
        bool found = false;
        for (int j = 0; j < baskets.size(); j++) {
            if  (baskets[j] >= fruits[i]) {
                found = true;
                baskets[j] = INT_MIN;
                break;
            }
        }
        if (!found)
            count++;
    }
    return count;
}

};