class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, greater<int>> minHeap;
        for (auto& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};