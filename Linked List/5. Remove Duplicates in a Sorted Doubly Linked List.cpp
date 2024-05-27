/*--------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------------------*/

Node * removeDuplicates(Node *head)
{
    if(head == NULL || head -> next == NULL) return head;
    Node* currNode = head;
    while(currNode){
        Node* nextNode = currNode -> next;
        while(nextNode && currNode -> data == nextNode -> data){
            currNode -> next = nextNode -> next;
            if(nextNode -> next) (nextNode -> next) -> prev = currNode;
            nextNode = currNode -> next;
        }
        currNode = currNode -> next;
    }
    return head;
}

/*
Question Link: https://www.naukri.com/code360/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283
Author: M.R.Naganathan
*/
