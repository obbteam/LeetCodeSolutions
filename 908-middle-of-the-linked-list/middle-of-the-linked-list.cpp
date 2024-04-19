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
    ListNode* middleNode(ListNode* head) {
        ListNode* array = head;
        int length = 0;

        while(array != nullptr) {
            array = array->next;
            length++;
        }
        int j =0;
        while(j<length/2) {
            head = head->next;
            j++;
        }
        return head;
    }
};