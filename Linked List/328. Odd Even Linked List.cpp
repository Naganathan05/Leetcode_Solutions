/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next || !((head -> next) -> next)){
            return head;
        }
        ListNode *even_node = head;
        ListNode *temp = head -> next;
        ListNode *odd_node = head -> next;
        ListNode *even_prev = head;
        ListNode *odd_prev = head;
        while(even_node || odd_node){
            even_prev -> next = even_node;
            odd_prev -> next = odd_node;
            even_prev = even_node;
            if(even_node && even_node -> next){
                even_node = (even_node -> next) -> next;
            }
            else{
                break;
            }
            odd_prev = odd_node;
            if(odd_node && odd_node -> next){
                odd_node = (odd_node -> next) -> next;
            }
            else{
                break;
            }
        }
        even_prev -> next = temp;
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/odd-even-linked-list/
Author: M.R.Naganathan
*/
