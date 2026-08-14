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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // loop over the curr until the end of the nodes.
        while (curr != nullptr) {
            // this preserves the nodes from the right side so it doesn't lose the pointing address that the pointer originally head.
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            // traverse the nodes
            curr = newNode;
        }
        return prev;
    }
};
