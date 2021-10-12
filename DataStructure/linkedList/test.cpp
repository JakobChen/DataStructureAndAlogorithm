
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
    
        
        // 打印链表
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