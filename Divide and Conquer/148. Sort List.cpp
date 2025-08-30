/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (fast && fast -> next) {
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }
        return slow;
    }

    void unionNodes(ListNode* &head, ListNode* &sortedCurrNode, ListNode* &targetNode){
        if (!head) {
            head = targetNode;
            sortedCurrNode = targetNode;
        } else {
            sortedCurrNode -> next = targetNode;
            sortedCurrNode = sortedCurrNode->next;
        }
        targetNode = targetNode -> next;
        sortedCurrNode -> next = NULL;
    }

    ListNode* mergeSortedLists(ListNode* firstHead, ListNode* secondHead) {
        ListNode* head = NULL;
        ListNode* sortedCurrNode = NULL;
        while (firstHead && secondHead) {
            if (firstHead -> val <= secondHead -> val) {
                unionNodes(head, sortedCurrNode, firstHead);
            } else {
                unionNodes(head, sortedCurrNode, secondHead);
            }
        }

        while (firstHead) unionNodes(head, sortedCurrNode, firstHead);
        while (secondHead) unionNodes(head, sortedCurrNode, secondHead);
        return head;
    }

    // ListNode* mergeSort(ListNode* head) {
    //     if (!head || !head -> next) return head;

    //     ListNode* middleNode = getMiddle(head);
    //     ListNode* rightStart = middleNode -> next;
    //     middleNode -> next = NULL;

    //     ListNode* firstListStart = mergeSort(head);
    //     ListNode* secondListStart = mergeSort(rightStart);
    //     return mergeSortedLists(firstListStart, secondListStart);
    // }

    ListNode* sortList(ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode* middleNode = getMiddle(head);
        ListNode* rightStart = middleNode -> next;
        middleNode -> next = NULL;

        ListNode* firstListStart = sortList(head);
        ListNode* secondListStart = sortList(rightStart);
        return mergeSortedLists(firstListStart, secondListStart);
    }
};

/*
Question Link: https://leetcode.com/problems/sort-list/
Author: M.R.Naganathan
*/
