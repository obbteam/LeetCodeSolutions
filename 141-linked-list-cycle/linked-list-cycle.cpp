/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;

        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next; // moves by 1 node
            hare = hare->next->next;   // moves by 2 nodes

            if (tortoise == hare) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle found
    }
};