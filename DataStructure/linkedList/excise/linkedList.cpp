
#include <iostream>
using  namespace std;

class LinkedList{
public:
    struct Node{
        Node* next;
        int val;
        Node(): val(0), next(nullptr){}
        Node(int v): val(v), next(nullptr){}
    };

    LinkedList():_size(0), _dummyHead(new Node(0)){}

    void AddAtHead(int value){
        Node* newNode = new Node(value);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        ++_size;
    }
    int GetAtIndex(int index){
        if(index < _size){
            Node* currNode = _dummyHead->next;
            while(index--){
                currNode = currNode->next;
            }
            return currNode->val;
        }

        return -1; 
    }
    void AddAtIndex(int index, int value){
        if( index>=0 && index < _size){
            Node* currNode = _dummyHead;
            while(index--){
                currNode = currNode->next;
            }
            Node* newNode = new Node(value);
            newNode->next = currNode->next;
            currNode->next = newNode;
            _size++;;
        }else{
            cout << "Out of range" << endl;
        }
    }
    void AddAtTail(int val){
        Node* currNode = _dummyHead;
        while(currNode->next != nullptr){
            currNode = currNode->next;
        } // jump out condition >> currNode == tail Node;
        Node* newNode = new Node(val);
        currNode->next = newNode;
        ++_size;
        
    }
    void DeleteAtIndex(int index){
        if(index>=0 && index < _size){
            Node* currNode = _dummyHead;
            while( index-- ){
                currNode = currNode->next;
            }
            Node* tempNode = currNode->next;
            currNode->next = tempNode->next;
            delete tempNode;
            --_size;
        }
        
    }
    void PrintList(){
        Node* curr = _dummyHead->next;
        while(curr->next != nullptr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }

private:
    int _size;
    Node* _dummyHead;

};



int main()
{
    cout << "Hello World" << endl;

    //int index = 1;
    LinkedList* obj = new LinkedList();
    //int param_1 = obj->get(index);
    int val = 10;
    obj->AddAtTail(10);

    obj->AddAtHead(val);
    obj->AddAtHead(12);
    obj->AddAtHead(13);
 
    obj->AddAtIndex(1,8);
    obj->AddAtIndex(0,7);

    cout << "Value at get()" << obj->GetAtIndex(0)<<endl;
    //obj->AddAtTail(10);
    //obj->addAtIndex(index,val);
    obj->PrintList();

    obj->DeleteAtIndex(1);
    cout << "Value at get()" << obj->GetAtIndex(1)<<endl;

    obj->PrintList();
    return 0;
}