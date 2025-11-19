class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int c = 0, cc = 0, n = distance.size();

        int i = start;
        while (i != destination) {
            c += distance[i];
            i = (i + 1) % n;
        }

        i = start;
        while (i != destination) {
            i--;
            if (i < 0) i = n - 1;
            cc += distance[i];
        }
        return min(c, cc);
    }
};