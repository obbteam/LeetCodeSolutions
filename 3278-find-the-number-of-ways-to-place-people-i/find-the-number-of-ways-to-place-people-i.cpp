class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(),
                  [](vector<int>& a, vector<int>& b) {
                      if (a[0] == b[0])
                          return a[1] > b[1];
                      return a[0] < b[0];
                  });

        int count = 0;
        // Step 2: Iterate through all points as potential "upper-left" points
        for (int i = 0; i < points.size(); i++) {
            int upperY = points[i][1]; // y-coordinate of upper-left point
            int lowerYLimit = INT_MIN;

            // Step 3: Check subsequent points as potential "bottom-right"
            // points
            for (int j = i + 1; j < points.size(); j++) {
                int currentY = points[j][1];

                // Valid pair if currentY is below upperY and above previous
                // lowerYLimit
                if (currentY <= upperY && currentY > lowerYLimit) {
                    count++;
                    lowerYLimit = currentY;

                    // Once we reach the same y as upperY, no more valid points
                    // possible
                    if (currentY == upperY)
                        break;
                }
            }
        }
        return count;
    }
};