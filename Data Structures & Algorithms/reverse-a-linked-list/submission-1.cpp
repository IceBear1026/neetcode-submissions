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

        // the reason why we want to do a loop with curr != nullptr is because curr will eventually be pointing at nullptr at the end of the loop after reversing everything. 
        while(curr != nullptr) {
            // keep the array in a temporary pointer so we can use it even if we detach the pointer from the current. 
            ListNode* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            // traverse;
            curr = newNode;
        }

        return prev;
    }
};
