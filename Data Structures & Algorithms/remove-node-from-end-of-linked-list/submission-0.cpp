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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            length++;
            curr = curr->next;
        }
        curr = head;
        if(length-n-1 == -1){
            head = head->next;
            return head;
        }
        else{
            int counter=0;
            while(counter != (length-n-1)){
                curr = curr->next;
                counter++;
            }
            curr->next = curr->next->next;
        }
        return head;
    }
};
