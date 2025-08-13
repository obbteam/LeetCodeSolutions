/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode *head) {
    int n = 0;
    auto *node = head;
    for (; node != nullptr; node = node->next)
        n++;

    n /= 2;
    node = head;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = node->val;
        node = node->next;
    }

    int maxSum = 0;

    for (int i = n - 1; i >= 0; --i) {
        maxSum = std::max(maxSum, arr[i] + node->val);
        node = node->next;
    }

    return maxSum;
}
};