class MyLinkedList {
public:
    // Definition for doubly-linked list.
    struct DoublyListNode {
        int val;
        DoublyListNode *next, *prev;
        DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    };
    MyLinkedList() {
         _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }
    
    int get(int index) {

    }
    
    void addAtHead(int val) {

    }
    
    void addAtTail(int val) {

    }
    
    void addAtIndex(int index, int val) {

    }
    
    void deleteAtIndex(int index) {

    }

private:
        DoublyListNode* _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        int _size = 0;
};
int main(){

    MyLinkedList* obj = new MyLinkedList();
    //int param_1 = obj->get(index);
    obj->addAtHead(10);
    //obj->addAtTail(val);
    //obj->addAtIndex(index,val);
    //obj->deleteAtIndex(index);
}