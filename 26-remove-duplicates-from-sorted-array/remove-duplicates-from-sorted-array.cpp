class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0; // If the vector is empty, return 0.

        int k =
            1; // Start counting from the first element, assuming it's unique.
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) { // Only if the current element is
                                          // different from the previous
                nums[k] = nums[i]; // Place it in the position of the next
                                   // unique element.
                k++;               // Increment the count of unique elements.
            }
        }
        return k; // The array from index 0 to k-1 now contains unique elements.
    }
};