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
        
        // this will loop over the linkedlist until the current hits the last node. 
        while(curr != nullptr) {
            // this will preserve the linkedlist from being lost.
            ListNode* newNode = curr->next;

            // detach the current node next pointer to prev. 
            curr->next = prev;

            // prev will now be pointing at originally of what curr was. And this will now create the new list. 
            prev = curr;

            // set the curr to the saved list and continue.
            curr = newNode;
        }
        return prev;
    }
};
