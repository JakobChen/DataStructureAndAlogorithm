/** Author: JC
 *设计链表
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/linked-list/fabl3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 * 
 * 
 * 
 */


#include<iostream>
using namespace std;
class MyLinkedList {
public:
    struct DoublelyListNode{
        int val;
        DoublelyListNode* prev;
        DoublelyListNode* next;
        DoublelyListNode(): val(0),prev(nullptr),next(nullptr){}
        DoublelyListNode(int v): val(v),prev(nullptr),next(nullptr){}
    };
    MyLinkedList() {
        _size = 0;
        _dummyHead = new DoublelyListNode();
        _dummyTail= new DoublelyListNode();
        _dummyHead->next = _dummyTail;
        _dummyTail->prev = _dummyHead;

    }
    ~MyLinkedList(){
        delete _dummyHead;
        delete _dummyTail;
        cout<<"dummyHead and dummyTail have been deleted!";
    }
    
    int get(int index) {
        //cout<<"size: "<<_size<<endl;
        if(index<_size){
            DoublelyListNode* curr = _dummyHead;
            while(index--)
            {
                curr = curr->next;
            }
            return curr->next->val; 
        }
        return -1;
    }
    
    void addAtHead(int val) {
        DoublelyListNode* curr = new DoublelyListNode(val);
        curr->next = _dummyHead->next;
        curr->prev = _dummyHead;
        _dummyHead->next->prev = curr;
        _dummyHead->next = curr;
        _size++;
    }
    
    void addAtTail(int val) {
        DoublelyListNode* curr = new DoublelyListNode(val);
        curr->next = _dummyTail;
        curr->prev = _dummyTail->prev;
        curr->prev->next= curr;
        _dummyTail->prev = curr;
        _size++;

    }
    
    void addAtIndex(int index, int val) {
        // the rigth range of the index could be same as the _size
        if(index<=_size){
            DoublelyListNode* newNode = new DoublelyListNode(val);
            DoublelyListNode* curr = _dummyHead;
            while(index--){
                curr = curr->next;
            }
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next->prev = newNode;
            curr->next = newNode;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index<_size){
            DoublelyListNode* curr = _dummyHead;
            while(index--){
                curr = curr->next;
            }
            if(curr->next != nullptr){
                DoublelyListNode* delNode = curr->next;
                curr->next = delNode->next;
                delNode->next->prev = curr;
                delete delNode;
                _size--;
            }
        }
    }
    void printList(){
        DoublelyListNode* curr = _dummyHead;
        while(curr->next != nullptr){
            curr = curr->next;
            cout << curr->val << " ";
        }
        cout<<endl;
    }
private:
    int _size;
    DoublelyListNode* _dummyHead;
    DoublelyListNode* _dummyTail;

};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){
    MyLinkedList* myList = new MyLinkedList();
    myList->addAtHead(2);
    myList->addAtHead(1);

    myList->addAtTail(3);
    myList->addAtTail(4);
    myList->addAtIndex(2,8);
    cout << "Get() " << myList->get(2) <<endl;
    myList->deleteAtIndex(2);
    myList->printList();
    return 0;
}