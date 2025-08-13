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
    ListNode* reverse(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* p = nullptr;
    ListNode* cur = head;
    while(cur){
        ListNode* f = cur->next;
        cur->next = p;
        p = cur;
        cur = f;
    }
    return p;
}

int pairSum(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    auto revList = reverse(slow->next);
    slow->next = nullptr;

    slow = head;
    int maxSum = 0;
    while (slow) {
        int sum = slow->val + revList->val;
        maxSum = std::max(maxSum, sum);
        slow = slow->next;
        revList = revList->next;
    }

    return maxSum;
}
};