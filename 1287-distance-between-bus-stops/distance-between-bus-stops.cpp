class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int c = 0, cc = 0, n = distance.size();

        int i = start;
        while (i != destination) {
            c += distance[i];
            i = (i + 1) % n;
        }

        int i2 = start;
        while (i2 != destination) {
            i2--;
            if (i2 < 0) i2 = n - 1;

            cc += distance[i2];
        }
        return min(c, cc);
    }
};