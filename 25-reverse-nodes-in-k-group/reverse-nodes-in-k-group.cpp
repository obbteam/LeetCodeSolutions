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
    // returns the start and saved nodes
    std::tuple<ListNode *, ListNode *, ListNode *> sliceFromTo(ListNode *head, ListNode *from, int k) {
        if (head != from) {
            auto cur = head;
            while (cur->next != from) {
                cur = cur->next;
            }
            cur->next = nullptr;
        }


        // we slice the start untill k
        auto node = from;
        for (int i = 0; i < k - 1; i++) {
            node = node->next;
        }
        // store the rest in next_nodes
        auto tail = node->next;
        node->next = nullptr;

        return {head, from, tail};
    }


    // recursion
    ListNode *swap_head(ListNode *head_copy) {
        if (head_copy->next == nullptr) return head_copy;

        // iterate to the end of the list saving the prev
        auto cur = head_copy;
        auto prev = head_copy;
        while (cur->next != nullptr) {
            cur = cur->next;
            if (cur->next) prev = prev->next;
        }
        prev->next = nullptr;
        cur->next = head_copy;
        cur->next = swap_head(cur->next);

        return cur;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        // if k == 1, do nothing
        if (k == 1) return head;

        // calculate num of nodes to know how many times I need to swap
        int num_nodes = 0;
        auto cur = head;
        while (cur != nullptr) {
            num_nodes++;
            cur = cur->next;
        }

        if (k > num_nodes) return head;

        auto tail = head;

        for (int i = 0; i < num_nodes / k; i++) {
            // slice linked list in place
            auto slicedList = sliceFromTo(head, tail, k);
            auto start = std::get<0>(slicedList);
            auto mid = swap_head(std::get<1>(slicedList));
            tail = std::get<2>(slicedList);

            if (i == 0) start = mid;

            cur = start;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            if (start != mid) cur->next = mid;

            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = tail;
            head = start;
        }
        return head;
    }
};