/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {

        if(head == NULL || head -> next == NULL){
            return true;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }

        ListNode* reversedList = reverse(slow);
        while(reversedList){
            if(head -> val != reversedList -> val) return false;
            head = head -> next;
            reversedList = reversedList -> next;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/palindrome-linked-list/
Author: M.R.Naganathan
*/
