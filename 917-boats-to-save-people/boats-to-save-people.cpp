class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int numberOfBoats = 0;
        int l = 0;
        int r = people.size() - 1;
        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                numberOfBoats++;
                l++;
                r--;
            }
            else{
                numberOfBoats++;
                r--;
            }
        }
        return numberOfBoats;
    }
};