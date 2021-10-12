
/*
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

*/



#include <iostream>
using  namespace std;


class MyLinkedList {
public:
    struct LinkedNode{
        int value;
        LinkedNode* next;
        LinkedNode(int val):value(val),next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }
    void addAtHead(int val) {
        LinkedNode* curr = new LinkedNode(val);
        curr->next = _dummyHead->next;
        _dummyHead->next = curr;
        _size++;
    }
    void addAtTail(int val) {
        LinkedNode* curr = new LinkedNode(val);
        LinkedNode* prev = _dummyHead;
        while(prev->next != nullptr){
            prev = prev->next;
        }
        prev->next = curr;
        _size++;
    }
    int get(int index) {
        if(index > _size -1 || index <0){
            return -1;
        }
        LinkedNode* curr = _dummyHead->next;
        while(index--){
            curr = curr->next;
        }
        return curr->value;
    }
    void addAtIndex(int index, int val) {
        
        if(index <= _size){ 
            LinkedNode* curr = new LinkedNode(val);
            LinkedNode* prev = _dummyHead; 
            while(index--){
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < _size && index>=0) {
            LinkedNode* prev = _dummyHead;
            while(index--){
                prev = prev->next;
            }
            //prev, curr, post
            LinkedNode* curr = prev->next;
            prev->next = curr->next;
            delete curr;
            _size--;
        }
    }
    
        
        // 
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode* _dummyHead;


};




int main()
{
    cout << "Hello World" << endl;

    //int index = 1;
    MyLinkedList* obj = new MyLinkedList();
    //int param_1 = obj->get(index);
    int val = 10;
    obj->addAtHead(val);
    obj->addAtHead(12);
    obj->addAtHead(13);
    obj->addAtTail(9);
    obj->addAtIndex(1,8);
    cout << "Value at get()" << obj->get(1)<<endl;
    //obj->addAtTail(val);
    //obj->printList();
    //obj->addAtIndex(index,val);
    obj->deleteAtIndex(1);
     
    obj->printLinkedList();
    return 0;
}