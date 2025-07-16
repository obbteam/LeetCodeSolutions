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
    int countNodes(ListNode* head) {
        int n = 0;
        while (head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int n = countNodes(head);
        n /= 2;
        if (n == 0)
            return nullptr;
        auto copy = head;
        for (int i = 0; i < n - 1; ++i) {
            copy = copy->next;
        }
        copy->next = copy->next->next;

        return head;
    }
};