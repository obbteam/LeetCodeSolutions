class Solution {
public:
    int trap(vector<int>& height) {
        // skip while height = 0
        size_t first = 0;
        while(height[first]==0 && first != height.size() - 1) {
            ++first;
        }
        
        if(first == height.size() - 1) return 0;
        int area = 0;


        while(first != height.size() - 1) {

            // skip to find the left wall
            while(height[first + 1]> height[first] && first + 1 != height.size() - 1) {
                ++first;
            }

            // skip to find the right wall
            auto second = first + 1;
            
            while(height[second] < height[first] && second != height.size() - 1) {
                ++second;
            }

            //check the if there is
            if(second == height.size() - 1) {
                    auto max = second;
                    while(first < second) {
                        if(height[second] >= height[max]) max = second;
                        second--;
                    }
                    second = max;
            }

            // if we are here we found the right wall and place for rain to collect
            area += std::min(height[first],height[second]) * (second - first - 1);
            ++first;
            while(first < second) {
                area -= height[first++];
            }
        }

        

        return area;
    }
};