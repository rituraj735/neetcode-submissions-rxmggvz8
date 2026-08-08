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
        ListNode *L=head, *R = head;
        int count = n;
        while(count--){
            R = R->next;
        }
        while(R != NULL && R->next!=NULL){
            L = L->next;
            R = R->next;
        }
        if(L== head && R== NULL){
            head =  NULL;
        }
        else{
            L->next = R;
        }
        return head;
    }
};
