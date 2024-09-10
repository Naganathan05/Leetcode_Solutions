/*------------------------------------
  Time Complexity: O(n * log(maxVal))
  Space Complexity: O(1)
---------------------------------------*/

class Solution {
public:
    int getGCD(int a, int b){
        if(b == 0) return a;
        return getGCD(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* curr = head;
        ListNode* nex = head -> next;
        while(nex){
            int gcd = getGCD(curr -> val, nex -> val);
            ListNode* newNode = new ListNode(gcd);
            curr -> next = newNode;
            newNode -> next = nex;
            curr = nex;
            nex = nex -> next;
        }
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
Author: M.R.Naganathan
*/
