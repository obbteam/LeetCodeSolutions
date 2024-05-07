
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
        ListNode* copy = head;
        ListNode* result = nullptr;
        while (copy != nullptr) {
            mystack.push(copy->val * 2);
            copy = copy->next;
        }
        ListNode* newTail = nullptr;
        int carry = 0;

        while (!mystack.empty()) {
            newTail = new ListNode(0, newTail);
            int last = mystack.top();
            int remainder = last%10;
            newTail->val = remainder + carry;
            if (last >= 10) carry = 1;
            else carry = 0;
            mystack.pop();
        }
        if(carry == 1) newTail = new ListNode(1, newTail);
        return newTail;
    }
};