/*-----------------------------------------------------------------------
  Time Complexity: O(n + m) =>   n, m:Number Of Nodes in the Linked Lists
  Space Complexity: O(1)
-------------------------------------------------------------------------*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode *head = NULL;
        ListNode *curr = head;

        while(true){
            if(l1 && l2){
                sum = l1 -> val + l2 -> val + carry;
                l1 = l1 -> next;
                l2 = l2 -> next;
            }
            else if(l1){
                sum = l1 -> val + carry;
                l1 = l1 -> next;
            }
            else if(l2){
                sum = l2 -> val + carry;
                l2 = l2 -> next;
            }
            else if(carry != 0){
                sum = carry;
            }
            else{
                break;
            }
            if(sum != 10){
                carry = sum/10;
            }
            else{
                carry = 1;
            }
            sum %= 10;
            ListNode *dummyNode = new ListNode(sum);
            if(head == NULL){
                head = dummyNode;
                curr = head;
            }
            else{
                curr -> next = dummyNode;
                curr = curr -> next;
            }
        }
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/add-two-numbers/
Author: M.R.Naganathan
*/
