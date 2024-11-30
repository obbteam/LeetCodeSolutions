class Solution {
public:
    int maxArea(vector<int>& height) {
        auto start = 0;
        auto end = height.size() - 1;
        int maximum = 0;

        while(start <= end) {
            int length = end - start;
            int temp = length * std::min(height[start],height[end]);

            if(height[start] > height[end]) --end;
            else if(height[start] <= height[end]) ++start;
            
            if(temp > maximum) maximum = temp;
        }
        return maximum;        
    }
};