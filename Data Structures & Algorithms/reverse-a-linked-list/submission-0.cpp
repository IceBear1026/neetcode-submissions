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

        while(curr != nullptr) {
            // we are saving the linkedlist using this. 
            ListNode* nextNode = curr->next;

            // then we are changing it to prev
            curr->next = prev;

            // now we are storing the prev to store the curr
            prev = curr;

            // curr now stored the address we just saved
            curr = nextNode;
        }

        return prev;
    }
};
