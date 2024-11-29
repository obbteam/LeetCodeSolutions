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
    ListNode* addTwoWithCarry(ListNode* l1, ListNode* l2, bool carry) {
        int to_add = 0;
        if(carry) to_add = 1;

        int num_to_add;

        if(l1==nullptr && l2 == nullptr) return carry? new ListNode(1) : nullptr;

        if(l1==nullptr && l2) {
            num_to_add = l2->val + to_add;
        } else if(l2 == nullptr && l1) {
            num_to_add = l1->val + to_add;
        } else if(l1 != nullptr && l2 != nullptr) {
            num_to_add = l1->val + l2->val + to_add;
        }


        if(num_to_add > 9) {
            num_to_add = num_to_add - 10;
            carry = true;
        } else carry = false;
        
        
        auto current = new ListNode(num_to_add);
        
        current->next = addTwoWithCarry(l1? l1->next: nullptr, l2 ? l2->next: nullptr, carry);

        return current;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        return addTwoWithCarry(l1, l2, false);
    }
};