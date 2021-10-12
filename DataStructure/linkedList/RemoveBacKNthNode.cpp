/*

19. Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* _dummyHead = new ListNode(0);
        _dummyHead->next = head;
        ListNode* p = _dummyHead;
        ListNode* q = _dummyHead;
        for(int i= 0; i<=n;i++){
            q = q->next;
        }
        while(q!=nullptr){
            p = p->next;
            q = q->next;
        }
        ListNode* tempNode = p->next;        
        p->next = p->next->next;
        delete tempNode;
        ListNode* retNode = _dummyHead->next;
        delete _dummyHead;
        return retNode;

    }
};