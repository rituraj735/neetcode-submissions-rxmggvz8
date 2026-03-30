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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL, *curr = slow->next, *next = slow->next;
        slow->next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr = prev;
        ListNode *temp = head;
        ListNode *tp1, *tp2;
        while(curr){
            tp1 = temp->next;
            tp2 = curr->next;
            temp->next = curr;
            curr->next = tp1;
            temp = tp1;
            curr = tp2;
        }
    }
};
