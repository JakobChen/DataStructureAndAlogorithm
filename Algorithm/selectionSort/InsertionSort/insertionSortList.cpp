
/*
147. Insertion Sort List
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000
*/


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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* _dummyHead = new ListNode();
        _dummyHead->next = head;
        ListNode* curr = head->next;
        ListNode* modifyNode = head;
        while(curr != nullptr){
            if(modifyNode->val > curr->val){
                ListNode* prev = _dummyHead;
                while(prev->next->val < curr->val){
                    prev = prev->next;
                }
                // find the modified value >0 val;
                modifyNode->next = curr->next;
                curr->next = prev->next;
                prev->next = curr;
            }else{
                //modifyNode = modifyNode->next;
                modifyNode = curr;
            }
                curr = modifyNode->next;
        }
        return _dummyHead->next;
    }
};