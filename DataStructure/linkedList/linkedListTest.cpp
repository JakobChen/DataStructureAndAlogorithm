#include <iostream>
using  namespace std;

class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr){}

    };
    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
         _size = 0;
    }


    int get(int index) {

        if(index > _size -1 || index <0){
            return -1;
        }
        LinkedNode* curr = _dummyHead->next;
        while(index--){
            curr  =  curr->next;
        }


        return curr->val;
    }
   
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }


    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = _dummyHead;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        
        if(index > _size ){
            cout << "Index out of rangee!" <<endl;
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = _dummyHead;
        while(index--){
            curr =  curr->next;
        }
        newNode->next  = curr->next;
        curr->next = newNode; 
        _size++;
    }


    
    void deleteAtIndex(int index) {
        if(index >=_size || index <0){
            return ;
        }
    
        LinkedNode* curr = _dummyHead;
        while (index--)
        {
            curr = curr->next;
        }
        LinkedNode* tempNode = curr->next;
        curr->next = curr->next->next;
        delete tempNode;
        _size--;
    }


        // 打印链表
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int _size;
    LinkedNode * _dummyHead;
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