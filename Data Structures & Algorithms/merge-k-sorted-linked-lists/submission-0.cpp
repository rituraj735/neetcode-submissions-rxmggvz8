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
    // let's return the result of 2 lists merge in either l1 or some other res list.
    ListNode* merge2Lists(ListNode* l1, ListNode* l2){
        ListNode *ptr1=l1, *ptr2=l2;
        ListNode *res= new ListNode(0);
        ListNode* ptr= res;
        while(ptr1 || ptr2){
            if(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                ptr->next = ptr1;
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }
            else if(ptr1->val > ptr2->val){
                ptr->next = ptr2;
                ptr2 = ptr2->next;
                ptr = ptr->next;
            }
            else{
                ListNode* tmp1 = ptr1->next, *tmp2 = ptr2->next;
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr1 = tmp1;
                ptr2 = tmp2;
            }
            }
            else if(ptr1){
                ptr->next = ptr1;
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }
            else{
                ptr->next = ptr2;
                ptr2 = ptr2->next;
                ptr = ptr->next;
            }
            
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* res=NULL;
        for(int i=0; i<n; i++){
            res = merge2Lists(res,lists[i]);
        }
        return res;
    }
};
