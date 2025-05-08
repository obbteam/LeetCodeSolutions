class Solution {
public:
    int trap(std::vector<int>& height) {
    int area = 0;
    int* l = &height.front();
    int* r = &height.back();
    int leftMax = *l;
    int rightMax = *r;

    while (l < r) {
        if (*l <= rightMax) {
            l++;
            if (leftMax - *l > 0)
                area += leftMax - *l;
            leftMax = std::max(*l, leftMax);
        }

        if (*r < leftMax) {
            r--;
            if (rightMax - *r > 0)
                area += rightMax - *r;
            rightMax = std::max(*r, rightMax);
        }
    }

    return area;
}
};