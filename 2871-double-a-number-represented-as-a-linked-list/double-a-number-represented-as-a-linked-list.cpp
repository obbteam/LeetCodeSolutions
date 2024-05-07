
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
    ListNode* doubleIt(ListNode* head) {
        stack<int> mystack;
        while (head != nullptr) {
            mystack.push(head->val * 2);
            head = head->next;
        }
        ListNode* newTail = nullptr;
        int carry = 0;

        while (!mystack.empty()) {
            newTail = new ListNode(0, newTail);
            newTail->val = mystack.top() % 10 + carry;
            if (mystack.top() >= 10)
                carry = 1;
            else
                carry = 0;
            mystack.pop();
        }
        if (carry == 1)
            newTail = new ListNode(1, newTail);
        return newTail;
    }
};