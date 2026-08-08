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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //make a carry variable for each addition
        int carry = 0;
        ListNode* ans = NULL;
        while(l1 || l2){
            int num1 = l1->val;
            int num2 = l2->val;
            int res = num1+num2;
            carry = res/10;
            int value = res%10;
            if(ans==NULL) 
        }
    }
};
